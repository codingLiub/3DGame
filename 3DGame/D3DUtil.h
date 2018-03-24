
//*****************************************************************************************
// Desc: D3DUtil.hͷ�ļ������ڹ���������Ķ���
//*****************************************************************************************

#pragma once


#ifndef HR
#define HR(x)    { hr = x; if( FAILED(hr) ) { return hr; } }			//HR()�꣬����ִ�д���ķ���
#endif


#ifndef SAFE_DELETE					
#define SAFE_DELETE(p)       { if(p) { delete (p);     (p)=NULL; } }    //SAFE_DELETE()��,ָ����Դ���ͷ�
#endif    

#ifndef SAFE_DELETE_ARRAY
#define SAFE_DELETE_ARRAY(p) { if(p) { delete[] (p);   (p)=NULL; } }	//SAFE_DELETE_ARRAY()�ָ꣬�������ָ����Դ���ͷ�
#endif    

#ifndef SAFE_RELEASE			
#define SAFE_RELEASE(p)      { if(p) { (p)->Release(); (p)=NULL; } }    //SAFE_RELEASE()��,COM��Դ���ͷ�
#endif

