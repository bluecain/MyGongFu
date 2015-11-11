#include "SelectGate.h"
#include <math.h>
#define PI acos(-1)
//�˵�����С���� ��С�ı�����1-MENU_SCALE
#define MENU_SCALE 0.3
//�˵�����б�� 
#define MENU_ASLOPE 60.0
//calcFunction(x) Ϊ x/(x+a),����aΪ����
#define CALC_A 1
//��������ʱ��
#define ANIMATION_DURATION  0.3f 
//�˵���Ĵ�С����Ļ�ı�������Ȼ����ͨ��setContentSize����
#define CONTENT_SIZE_SCALE (2.0/3)
//�˵������˵����ȵı��� ����һ���˵���ȣ��˵���仯һ��
#define ITEM_SIZE_SCALE (1.0/4)
/*
�������滹�п������õĲ���������û��һһ�������������
*/
USING_NS_CC;

bool SelectGate::init(){
	if (!Layer::init())
		return false;
	_index = 0;
	_lastIndex = 0;
	this->ignoreAnchorPointForPosition(false);
	_selectedItem = nullptr;
	auto size = Director::getInstance()->getWinSize();
	this->setContentSize(size*CONTENT_SIZE_SCALE);
	this->setAnchorPoint(Point(0.5f, 0.5f));
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(SelectGate::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(SelectGate::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(SelectGate::onTouchEnded, this);
	getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
	return true;
};

void SelectGate::addMenuItem(cocos2d::MenuItem *item){
	item->setPosition(this->getContentSize().width / 2, this->getContentSize().height / 2);
	this->addChild(item);
	_items.pushBack(item);
	reset();
	//���ϣ����ʼû���ƶ�Ч�����ĳ�updatePosition��������
	updatePositionWithAnimation();
	return;
}
void SelectGate::updatePosition(){
	auto menuSize = getContentSize();
	for (int i = 0; i < _items.size(); i++){
		//����λ��
		float x = calcFunction(i - _index, menuSize.width / 2);
		_items.at(i)->setPosition(Point(menuSize.width / 2 + x, menuSize.height / 2));
		//����zOrder,������˳��
		_items.at(i)->setZOrder(-abs((i - _index) * 100));
		//������������
		_items.at(i)->setScale(1.0 - abs(calcFunction(i - _index, MENU_SCALE)));
		//������б��Nodeû��setCamera��������OrbitCamera������ʱ����Ϊ0���ﵽЧ��
		auto orbit1 = OrbitCamera::create(0, 1, 0, calcFunction(i - _lastIndex, MENU_ASLOPE), calcFunction(i - _lastIndex, MENU_ASLOPE) - calcFunction(i - _index, MENU_ASLOPE), 0, 0);
		_items.at(i)->runAction(orbit1);
	}
	return;
}
void SelectGate::updatePositionWithAnimation(){
	//��ֹͣ���п��ܴ��ڵĶ���
	for (int i = 0; i < _items.size(); i++)
		_items.at(i)->stopAllActions();
	auto menuSize = getContentSize();
	for (int i = 0; i < _items.size(); i++){
		_items.at(i)->setZOrder(-abs((i - _index) * 100));
		float x = calcFunction(i - _index, menuSize.width / 2);
		auto moveTo = MoveTo::create(ANIMATION_DURATION, Point(menuSize.width / 2 + x, menuSize.height / 2));
		_items.at(i)->runAction(moveTo);
		auto scaleTo = ScaleTo::create(ANIMATION_DURATION, (1 - abs(calcFunction(i - _index, MENU_SCALE))));
		_items.at(i)->runAction(scaleTo);
		auto orbit1 = OrbitCamera::create(ANIMATION_DURATION, 1, 0, calcFunction(i - _lastIndex, MENU_ASLOPE), calcFunction(i - _index, MENU_ASLOPE) - calcFunction(i - _lastIndex, MENU_ASLOPE), 0, 0);
		_items.at(i)->runAction(orbit1);
	}
	scheduleOnce(schedule_selector(SelectGate::actionEndCallBack), ANIMATION_DURATION);
	return;
}
void SelectGate::reset(){
	_lastIndex = 0;
	_index = 0;
}
void SelectGate::setIndex(int index){
	_lastIndex = _index;
	this->_index = index;
}
float SelectGate::getIndex(){
	return _index;
}

MenuItem * SelectGate::getCurrentItem(){
	if (_items.size() == 0)
		return nullptr;
	return _items.at(_index);
}

bool SelectGate::onTouchBegan(Touch* touch, Event* event){
	//��ֹͣ���п��ܴ��ڵĶ���
	for (int i = 0; i < _items.size(); i++)
		_items.at(i)->stopAllActions();
	if (_selectedItem)
		_selectedItem->unselected();
	auto position = this->convertToNodeSpace(touch->getLocation());
	auto size = this->getContentSize();
	auto rect = Rect(0, 0, size.width, size.height);
	if (rect.containsPoint(position)){
		return true;
	}
	return false;
}
void SelectGate::onTouchEnded(Touch* touch, Event* event){
	auto size = getContentSize();
	auto xDelta = touch->getLocation().x - touch->getStartLocation().x;
	rectify(xDelta>0);
	if (abs(xDelta)<size.width / 24 && _selectedItem)
		_selectedItem->activate();
	updatePositionWithAnimation();
	return;
}
void SelectGate::onTouchMoved(Touch* touch, Event* event){
	auto xDelta = touch->getDelta().x;
	auto size = getContentSize();
	_lastIndex = _index;
	_index -= xDelta / (size.width *ITEM_SIZE_SCALE);
	updatePosition();
	return;
}

void SelectGate::rectify(bool forward){
	auto index = getIndex();
	if (index < 0)
		index = 0;
	if (index>_items.size() - 1)
		index = _items.size() - 1;
	if (forward){
		index = (int)(index + 0.4);
	}
	else
		index = (int)(index + 0.6);
	setIndex((int)index);
}

void SelectGate::actionEndCallBack(float dx){
	_selectedItem = getCurrentItem();
	if (_selectedItem)
		_selectedItem->selected();
}

float SelectGate::calcFunction(float index, float width){
	return width*index / (abs(index) + CALC_A);
}