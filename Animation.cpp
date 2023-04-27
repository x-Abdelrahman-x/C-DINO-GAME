#pragma once
#include "Animation.h"

Animation::Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime)
{
	this ->imageCount = imageCount;
	this -> swichTime = switchTime;
	totalTime = 0.0f;
	currentImage.x = 0;
	uvRict.width  = 100 / float(imageCount.x);
	uvRict.height =400 / float(imageCount.y);
}

Animation::~Animation()
{
}

void Animation::Update(int row, float deltaTime)
{

	currentImage.y = row;
	totalTime += deltaTime;

		if (totalTime >= swichTime)
		{
			totalTime -= swichTime;
			currentImage.x++;
			if (currentImage.x >= imageCount.x)
			{
				currentImage.x = 0;
			}
		}
		uvRict.left = currentImage.x * uvRict.width;
		uvRict.top = currentImage.y * uvRict.height;
}
