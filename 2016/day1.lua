 s = "R3, L5, R1, R2, L5, R2, R3, L2, L5, R5, L4, L3, R5, L1, R3, R4, R1, L3, R3, L2, L5, L2, R4, R5, R5, L4, L3, L3, R4, R4, R5, L5, L3, R2, R2, L3, L4, L5, R1, R3, L3, R2, L3, R5, L194, L2, L5, R2, R1, R1, L1, L5, L4, R4, R2, R2, L4, L1, R2, R53, R3, L5, R72, R2, L5, R3, L4, R187, L4, L5, L2, R1, R3, R5, L4, L4, R2, R5, L5, L4, L3, R5, L2, R1, R1, R4, L1, R2, L3, R5, L4, R2, L3, R1, L4, R4, L1, L2, R3, L1, L1, R4, R3, L4, R2, R5, L2, L3, L3, L1, R3, R5, R2, R3, R1, R2, L1, L4, L5, L2, R4, R5, L2, R4, R4, L3, R2, R1, L4, R3, L3, L4, L3, L1, R3, L2, R2, L4, L4, L5, R3, R5, R3, L2, R5, L2, L1, L5, L1, R2, R4, L5, R2, L4, L5, L4, L5, L2, L5, L4, R5, R3, R2, R2, L3, R3, L2, L5"
 test = "R8, R4, R4, R8"
 f = "N"
 cstr = "NESW"
 cfac = 1
 cloc = {0, 0}
 sum = 0
 vloc = {}
 
 local function hasVisited(v, c)
	for i=1, #v do
		--print(string.format("Check: [%d,%d] to [%d,%d]", v[i][1], v[i][2], c[1], c[2]))
		if v[i][1] == c[1] and v[i][2] == c[2] then
			return true
		end
	end
	return false
end
 
     for w in string.gmatch(s, "([^,]*)") do
		w = string.gsub(w, "%s+", "")
		--print(w)
		dir = w:sub(1,1)
		distance = w:sub(2,-1)
		if dir == "R" then
			cfac = cfac + 1
			if cfac > 4 then
				cfac = 1
			end
			f = cstr:sub(cfac,cfac)
		elseif dir == "L" then
			cfac = cfac - 1
			if cfac < 1 then
				cfac = 4
			end
			f = cstr:sub(cfac,cfac)
		end
		for i = 1, distance do
			if f == "N" then
				cloc[2] = cloc[2] - 1
			elseif f == "E" then
				cloc[1] = cloc[1] + 1
			elseif f == "S" then
				cloc[2] = cloc[2] + 1
			elseif f == "W" then
				cloc[1] = cloc[1] - 1
			end
			if hasVisited(vloc, cloc) then
				sum = math.abs(cloc[1]) + math.abs(cloc[2])
				print(sum)
				return
			else	
				table.insert(vloc, {cloc[1], cloc[2]})
			end
		end
		--print(string.format("Curret facing: %s", f))
	--   print(string.format("Dir: %s, Distance: %d", dir, distance))
     end