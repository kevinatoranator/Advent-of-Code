 keypad = {{1,2,3},{4,5,6},{7,8,9}}
 wackkeypad = {{0,0,1,0,0},{0,2,3,4,0},{5,6,7,8,9},{0,"A","B","C",0},{0,0,"D",0,0}}
 
 currentLoc = {3,1}
 for line in io.lines("input.txt") do
	for c in line:gmatch"." do
		--print(c)
		if c == "U" and currentLoc[1] + currentLoc[2] > 4 and currentLoc[1] - currentLoc[2] > -2 then
			currentLoc[1] = currentLoc[1] - 1
		elseif c == "D" and currentLoc[1] - currentLoc[2] < 2 and currentLoc[1] + currentLoc[2] < 8 then
			currentLoc[1] = currentLoc[1] + 1
		elseif c == "L" and currentLoc[1] + currentLoc[2] > 4 and currentLoc[1] - currentLoc[2] < 2 then
			currentLoc[2] = currentLoc[2] - 1
		elseif c == "R" and currentLoc[1] - currentLoc[2] > -2 and currentLoc[1] + currentLoc[2] < 8 then
			currentLoc[2] = currentLoc[2] + 1
		end
		--print(currentLoc[1], currentLoc[2])
	end
	print(wackkeypad[currentLoc[1]][currentLoc[2]])
	
	--print(line)
end