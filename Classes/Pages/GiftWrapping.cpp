#include <iostream>
#include <random>

#include "Pages/GiftWrapping.h"
#include "Math/Point.h"

USING_NS_CC;

bool GiftWrapping::init()
{
	if ( !Node::init() )
	{
		return false;
	}
    
	SetupUI();
	
	return true;
}

void GiftWrapping::SetupUI()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	//////////////////////////////////////////////////////////////////////////
	ui::Button *btn = ui::Button::create("CloseNormal.png", "CloseSelected.png");
	btn->setPosition(origin/2 + visibleSize/2);
	btn->addClickEventListener(CC_CALLBACK_1(GiftWrapping::BtnCallback1,this));
	addChild(btn);
}

void GiftWrapping::GenratePoints(int n) {
    std::random_device rd;
    std::mt19937 mt(1370); //1370: deterministic or rd(): non-determinstic 32-bit seed
    std::uniform_int_distribution<int> dist(0,99);
    std::cout<<"Generated: ";
    for(int i=0; i<n; ++i) {
        int x=dist(mt), y=dist(mt);
        inputPoints.push_back(new CompGeoVis::Point(x,y));
        std::cout<<"["<<x<<","<<y<<"] ";
    }
    std::cout<<std::endl;
}

void GiftWrapping::RenderPoints()
{
    auto it = inputPoints.begin();
    for(;it!=inputPoints.end();it++) {
        auto s = Sprite::create("point.png");
        s->setPosition((*it)->getX(), (*it)->getY());
        this->addChild(s);
    }
}

void GiftWrapping::BtnCallback1(Ref *pSender) {
    GenratePoints(30);
    RenderPoints();
}
