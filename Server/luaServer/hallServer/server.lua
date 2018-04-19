module(..., package.seeall)

local server = nil
local connections = {}
local dbs = {}
local connect_count = 0
local db_count = 0
local times = 0

function startServer()
	SetStateFunc{load = load, update = update}
	init()
	start()
end

function init()
	print("init")
	-- body
end

function start()
	print("start")
	-- body
end

function load()
	createServer(Config.ServerHost,Config.ServerPort);
	connectToDbServer(Config.DbHost,Config.DbPort);
	print("load success")
	return true
	-- body
end

function update(frame)
	times = times + 1
	if times > 60 then
		for i,v in ipairs(dbs) do
			v.luaSendData(7)
		end
		times = 0
	end
	return true
	-- body
end

function shutdown()
	print("shutdown")
	return true
	-- body
end

function newConnect(packet)
	print("newConnect",packet)
	connect_count = 1+ connect_count
	local connect = {
		id = connect_count,
		packet = packet
	}
	connections[connect_count] = connect
	packet.connect = connect

	packet.recvData = recvData
	packet.disConnect = disConnect
end

function disConnect(packet)
	print("disConnect",packet)
	-- body
end

function recvData(packet)
	print("recvData",packet.luaGetCmd(),packet.luaRecvData(),packet)
	-- print("recvData",cmd,data,packet)
	-- body
end

function connectToDbServer(host,port)
	print("start connect to db",host,port)
	local db = ConnectServer(host,port)
	if db then 
		db.recvData = recvData
		db.disConnect = disConnect
		print("connect to db success")
		table.insert(dbs,db)
	else
		print("connect to db failed!")
	end
	print("result",db)
	-- body
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
	-- body
end