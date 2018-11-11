#ifndef __Class_1X2Y3Z_H__
#define __Class_1X2Y3Z_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "Const/macros.h"

class Class_1X2Y3Z : public cocos2d::Node
{
public:
	CREATE_FUNC(Class_1X2Y3Z);
	//CREATE_FUNC_PARAM1_Ptr(Class_1X2Y3Z, Foo, foo);
	/*static Class_1X2Y3Z* create();*/
	virtual bool init();
	
private:
	void SetupUI();
	//void SetupUI_XXX();
	//////////////////////////////////////////////////////////////////////////
	
	//callback
	void BtnCallback1(Ref *pSender);
	void BtnCallback2(Ref *pSender, cocos2d::ui::Widget::TouchEventType type);
};

#endif // __Class_1X2Y3Z_H__
