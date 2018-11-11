#include "Class_1X2Y3Z.h"
#include "Scene/MainMenu/MainMenu.h"
#include "Scene/Common/Bar.h"
#include "Const/constants_z_order.h"

USING_NS_CC;

// Class_1X2Y3Z* Class_1X2Y3Z::create()
// {
// 	Class_1X2Y3Z *pRet = new Class_1X2Y3Z();
// 	if (pRet && pRet->init())
// 	{
// 		pRet->autorelease();
// 		return pRet;
// 	}
// 	else
// 	{
// 		delete pRet;
// 		pRet = NULL;
// 		return NULL;
// 	}
// }

bool Class_1X2Y3Z::init()
{
	if ( !Node::init() )
	{
		return false;
	}

	SetupUI();
	
	return true;
}

void Class_1X2Y3Z::SetupUI()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	//////////////////////////////////////////////////////////////////////////
	// Old System of Creating Menu and Buttons
	/*auto menu = Menu::create();
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, Z_NORMAL);
	//
	auto backBtn = MenuItemImage::create(
		"setting-normal.png",
		"setting-normal.png",
		CC_CALLBACK_1(Class_1X2Y3Z::ReleasedBackBtn, this));

	backBtn->setPosition(Vec2(origin.x + visibleSize.width - backBtn->getContentSize().width/2 ,
								origin.y + backBtn->getContentSize().height/2));
	menu->addChild(backBtn, Z_HIGH);*/
	//////////////////////////////////////////////////////////////////////////
	ui::Button *btn = ui::Button::create("CloseNormal.png", "CloseSelected.png");
	btn->setPosition(origin/2 + visibleSize/2);
	btn->addClickEventListener(CC_CALLBACK_1(Class_1X2Y3Z::BtnCallback1,this));
	btn->addTouchEventListener(CC_CALLBACK_2(Class_1X2Y3Z::BtnCallback2,this));
	addChild(btn);
	//////////////////////////////////////////////////////////////////////////

	auto sprite = Sprite::create("Class_1X2Y3Z.png");
	sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
	this->addChild(sprite, Z_BACKGROUND);
	
}

void Class_1X2Y3Z::BtnCallback1(Ref *pSender)
{
	// When Button Released, Then ...
}
void Class_1X2Y3Z::BtnCallback2(Ref *pSender, cocos2d::ui::Widget::TouchEventType type)
{
	if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
	{
		auto director = Director::getInstance();
		auto scene = Scene::create();

		auto mainMenu = MainMenu::create();
		mainMenu->setPosition(Vec2::ZERO);
		scene->addChild(mainMenu);
		
		auto bar = Bar::create();
		bar->setPosition(Vec2::ZERO);
		scene->addChild(bar);

		// run
		director->replaceScene(scene);
	}
}