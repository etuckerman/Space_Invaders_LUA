

-- WORLD ----------------------------------------|
-- math.random(1,255)						   --|
-- math.random(1,25)						   --|
worldColour = 100							   --|
worldLevel = 25								   --|
											   --|
math.randomseed(os.time())					   --|
											   --|
function randomNumber()						   --|
	return math.random(1,10000)				   --|
end											   --|
											   --|
											   --|
-- PLAYER ---------------------------------------|
playerLives = 10							   --|
playerSprite = "assets/VikingsMED.bmp"		   --|
--playerSprite2 =	"assets/ENEMY2.bmp"		   --|
playerReduceLivesAmount = 2					   --|
playerStartpos = { x = 500, y = 600}		   --|
playerLaser = "assets/player0.bmp"			   --|
											   --|
function right(x, currentFrame)				   --|
	x = x+5									   --|
	if(x >= 910)							   --|
	then									   --|
		x = 910								   --|
	end										   --|
	if(currentFrame > 1.9)					   --|
	then									   --|
		currentFrame = 0					   --|
	end										   --|
	return x, currentFrame					   --|
end											   --|
											   --|
function left(x, currentFrame, directionFlag)  --|
	directionFlag = false					   --|
	currentFrame = currentFrame + 0.1		   --|
	x = x-5									   --|
	if (x <= -0)							   --|
	then									   --|
		x = -0								   --|
	end										   --|
	if (currentFrame > 1.9)					   --|
	then									   --|
		currentFrame = 0					   --|
	end										   --|
	return x, currentFrame, directionFlag	   --|
end											   --|
											   --|
function setPlayerScore()--part 2			   --|
	CDispatcher("setScore", 5000)			   --|
end											   --|
											   --|
-- MOTHERSHIP -----------------------------------|
mothershipSprite = "assets/Mothership2.bmp"	   --|
mothershipStartpos = { x = 0, y = 20}		   --|
											   --|
-- UFO ------------------------------------------|
ufoSprite = "assets/Mothership2.bmp"				   --|
ufoSprite2 = "assets/ENEMY3.bmp"			   --|
ufoLaser = "assets/Ship_placeholder.bmp"	   --|
--ufoStartpos = { x = 600, y = 600}			   --|
											   --|
function UFOleft(counter, currentFrame, level) --|
	directionFlag = false					   --|
	currentFrame = currentFrame + 0.1		   --|
	x = x-(0.5+(counter/17)+(level/40))		   --|
	if (currentFrame > 1.9)					   --|
	then									   --|
		currentFrame = 0					   --|
	end										   --|
	return counter, currentFrame, level		   --|
end											   --|
											   --|
											   --|
											   --|
function UFOright(counter, currentFrame, level)--|
	directionFlag = true					   --|
	currentFrame = currentFrame + 0.1		   --|
	x = x+(0.5+(counter/17)+(level/40))		   --|
	if (currentFrame > 1.9)					   --|
	then									   --|
		currentFrame = 0;					   --|
	end										   --|
	return counter, currentFrame, level		   --|
end											   --|
											   --|
											   --|
-- GAME -----------------------------------------|
function callMessage()						   --|
	display_message("Get a Life", 1)		   --|
end											   --|
											   --|
function callStartScreen()					   --|
	game_start_message(10,10)				   --|
end											   --|
-------------------------------------------------|