math.randomseed(os.time())

function randomNumber()
	return math.random(1,10000)
end

function right(x, currentFrame)
	x = x+5
	if(x >= 910)
	then
		x = 910
	end
	if(currentFrame > 1.9)
	then
		currentFrame = 0
	end
	return x, currentFrame
end

-- WORLD
worldColour = 100
worldLevel = 25
-- PLAYER
playerLives = 10
playerSprite = "assets/Ufoph.bmp"
playerReduceLivesAmount = 2
playerStartpos = { x = 500, y = 625}
--MOTHERSHIP
mothershipSprite = "assets/Mothership2.bmp"
mothershipStartpos = { x = 0, y = 20}