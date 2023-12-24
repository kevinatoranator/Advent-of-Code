package.path = package.path .. ";C:\\Users\\krinald\\AppData\\Roaming\\luarocks\\share\\lua\\5.4\\?.lua"
md5 = require("md5")

input = "ojvtpuvg"
tinput = "abc"

code = {nil,nil,nil,nil,nil,nil,nil,nil}

currentNum = 0
foundNums = 0
while foundNums < 8 do
	--print(currentNum)
	testInput = input .. currentNum
	hex = md5.sumhexa(testInput)
	--print(hex)
	if string.sub(hex, 1, 5) == "00000" then
		loc = string.sub(hex, 6, 6)
		loc = tonumber(string.sub(hex, 6, 6))
		if loc ~= nil then
			if loc < 8 and code[loc+1] == nil then
				print(loc+1, string.sub(hex, 7, 7))
				code[loc+1] = string.sub(hex, 7, 7)
			--print(code[1], code[2], code[3], code[4], code[5], code[6], code[7], code[8])
				foundNums = foundNums + 1
			end
		end
	end
	currentNum = currentNum + 1
end
print(code[1], code[2], code[3], code[4], code[5], code[6], code[7], code[8])