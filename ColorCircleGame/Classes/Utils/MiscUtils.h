#pragma once

#define DEF_CURRENT(type) \
protected: static type* m_pCurrent;\
public: static type* getCurrent()\
{\
	return m_pCurrent;\
}

#define CREATE_FUNC_WITH_PARAM(type, paramType) \
public: static type* create(paramType param) \
{\
	type* obj = new type();\
	if (obj && obj->init(param))\
	{\
		obj->autorelease();\
		return obj;\
	}\
	else\
	{\
		delete obj;\
		obj = NULL;\
		return NULL;\
	}\
}