EntityData = {}
function EntityData.new(name,x,y,speed_multipiler,xSpeed,ySpeed,ID,CustomData)
	local entitydata = {}
	entitydata.name = name
	entitydata.x = x
	entitydata.y = y
	entitydata.ID = ID
	entitydata.CustomData = CustomData
	return entitydata
	--print(entitydata.name)
end
function EntityData.ConvertToC(name,x,y,ID)

end
EntityData.new("Test",0.0,0.0,0,0,0,1,0)