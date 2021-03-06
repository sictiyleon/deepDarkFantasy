module(..., package.seeall)

local rank = require "rank.rank"
local matchMgr = require "match.matchMgr"
local roleMgr = require "role.roleMgr"

local dbHandler = require "dbhandler"
local loginHandler = require "loginhandler"
local gameHandler = require "gamehandler"
local command = require "luaBase.command"
local Event = require "luaBase.eventdispatcher"
local LoginPb = require "Login_pb"


local server = nil
local connections = {}
local connect_count = 0
local times = 0

function startServer()
	print("startServer")
	SetStateFunc{load = load, update = update}
	init()
	start()
end

function init()
	createServer(Config.ServerHost,Config.ServerPort);
	dbHandler.init()
	loginHandler.init()
	rank.init()
	roleMgr.init()
	matchMgr.init()
	print("init")
end

function start()
	loginHandler.regist(connect_count,Config.ServerHost,Config.ServerPort)
	print("start")
end

function load()
	rank.load()
	print("load success")
	return true
end

function update(frame)
	times = times + 1
	if times > 600 then
		dbHandler.breathe()
		times = 0
	end
	return true
end

function shutdown()
	print("shutdown")
	return true
end

function createServer(host,port)
	server = CreateServer(host,port)
	if server then
		server.newConnect = newConnect
	else
		print("createServer failed!")
		os.exit(1)
	end
	print(server)
end

function newConnect(packet)
	print("newConnect",packet)
	connect_count = 1+ connect_count
	local connect = {
		id = connect_count,
		packet = packet,
		new = true
	}
	connections[connect_count] = connect
	packet.connect = connect

	packet.recvData = recvData
	packet.disConnect = disConnect

	--from client
	rank.sendRank(connect)
end

function disConnect(packet)
	print("disConnect",packet)
end

function recvData(packet)
	print("recvData--------------",packet.luaGetCmd())
	local connect = packet.connect
	if connect and connect.new then
		connect.new = false
		print("first connect")
	end
	processData(packet.connect,packet.luaGetCmd(),packet.luaRecvData())
end

function processData(connect, cmd, data)
	if cmd = command.c2s_login then
		local request = LoginPb.AccountInfo()
		request:ParseFromString(data)
		connect.roleId = request.id
		roleMgr.login(connect, data)
		print("login")
	end
	if connect.roleId ~= nil then
		Event.dispatcher("recvData", connect, cmd, data)
	end
	gameHandler.processData(connect, cmd, data)	
end