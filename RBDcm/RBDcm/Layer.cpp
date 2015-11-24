#include "StdAfx.h"
#include "Layer.h"
#include "ImgLayer.h"
#include "ImgInfo.h"


CLayer::CLayer(void)
{

}


CLayer::~CLayer(void)
{
}


CLayer* CLayer::Create(int nType)
{
	switch (nType)
	{
		case IMG_LAYER:
			return new CImgDataLayer;   //����ͼ��������ʾ��
		case IMG_INFO_LAYER:
			return new CImgInfoLayer;    //����ͼ����Ϣ��ʾ��
		default:
			return NULL;
	}
}