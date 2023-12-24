
 
 local function isTriangle(s1, s2, s3)
	if s1 + s2 <= s3 then
		return false
	elseif s1 + s3 <= s2 then
		return false
	elseif s2 + s3 <= s1 then
		return false
	end
	--print(s1, s2, s3)
	return true
end


triangles = 0
currentSide = 0 -- line %3
triangle1 = {0, 0, 0}
triangle2 = {0, 0, 0}
triangle3 = {0, 0, 0}

currentSide = 1
for line in io.lines("input.txt") do
	currentTriangle = 1
	line = line:gsub("%s+", " ")
	line = line:gsub('^%s*(.-)%s*$', '%1')
	--print(line)
    for w in string.gmatch(line, "([^%s+]*)") do
		--print(w)
		if currentSide % 3 == 0 then
			--print("mod 3", w)
			if currentTriangle == 1 then
				triangle1[3] = tonumber(w)
			elseif currentTriangle == 2 then
				triangle2[3] = tonumber(w)
			else
				triangle3[3] = tonumber(w)
				if isTriangle(triangle1[1], triangle1[2], triangle1[3]) then
					triangles = triangles + 1
					print(triangle1[1], triangle1[2], triangle1[3])
					print(triangles)
				end
				if isTriangle(triangle2[1], triangle2[2], triangle2[3]) then
					triangles = triangles + 1
					print(triangle2[1], triangle2[2], triangle2[3])
					print(triangles)
				end
				if isTriangle(triangle3[1], triangle3[2], triangle3[3]) then
					triangles = triangles + 1
					print(triangle3[1], triangle3[2], triangle3[3])
					print(triangles)
				end
			end
		elseif currentSide % 3 == 1 then
			if currentTriangle == 1 then
				triangle1[1] = tonumber(w)
			elseif currentTriangle == 2 then
				triangle2[1] = tonumber(w)
			else
				triangle3[1] = tonumber(w)
			end
		elseif currentSide % 3 == 2 then
			if currentTriangle == 1 then
				triangle1[2] = tonumber(w)
			elseif currentTriangle == 2 then
				triangle2[2] = tonumber(w)
			else
				triangle3[2] = tonumber(w)
			end
		end
		currentTriangle = currentTriangle + 1
    end
	currentSide = currentSide + 1
	--print(triangle[1], triangle[2], triangle[3])
end
print(triangles)