#pragma once
#include <vector>
#include "Camera.h"
#include"Arrow.h"
#include <d3d9.h>
#include <d3dx9.h>
#include "AllocateHierarchy.h"										//������������
#include "Direct3DInput.h"
#include "Terrain.h"

static	int	totalExp[15] = { 100,120,140,160,180,200,220,240,260,280,300,320,340,360,380 };//���ȼ��ܵ�Exp

// �ذ�Ķ���ṹ
struct CUSTOMVERTEX
{
	float _x, _y, _z;
	float _u, _v;
	CUSTOMVERTEX(float x, float y, float z, float u, float v)
		: _x(x), _y(y), _z(z), _u(u), _v(v) {}
};
#define D3DFVF_CUSTOMVERTEX  (D3DFVF_XYZ | D3DFVF_TEX1)


enum Team { Red, Blue, Creep};//����ö������
extern  std::vector < Arrow * >			g_vArrow;

class Character
{
public:
	LPDIRECT3DDEVICE9						pd3dDevice;
	Direct3DInput *							pInput;
	Terrain *							    pTerrain;
	Camera *                                pCamera;

	std::vector<Character * > *				pCharacter;

	float									fTimeDelta;

	//��������
	LPD3DXFRAME								pFrameRoot;
	CAllocateHierarchy*						pAllocateHier;
	LPD3DXANIMATIONCONTROLLER				pAnimController;

	//HP
	LPDIRECT3DVERTEXBUFFER9					HPBuffer;    // HP���㻺�����
	LPDIRECT3DTEXTURE9						HPTexture;    // HP��������
	LPDIRECT3DVERTEXBUFFER9					HPBackBuffer;    // HP���㻺����󱳾�
	LPDIRECT3DTEXTURE9						HPBackTexture;    // HP�������󱳾�


	D3DXMATRIX								model;
	DWORD									walk;
	DWORD									run;
	DWORD									idle;
	DWORD									attack;

	DWORD									currentAnim;
	UINT									currentTrack;

	bool									userControl;

	D3DXVECTOR3								position;
	D3DXVECTOR3								targetPosition;

	float									facing;
	float									facingTarget;
	float									alongXRotation;
	float									alongYRotation;
	float									alongZRotation;

	float									scaling;

	float									preTime;
	float									curTime;

	int                                     Type;//��������ˮ������
	//--------------��ɫ����-------------------//
	int										id;//�±�
	Team									team;//����
	int										species;//0 hero,1 tower,2 soliders,3 monster

	bool									alive;//�Ƿ����
	int										level;//�ȼ�
	int										hp;//Ѫ��
	int										exp;//����ֵ
	int										atk;//������
	int										def;//������

	float									walkSpeed;//��·�ٶ�
	float									runSpeed; //�ܲ��ٶ�
	float									turnSpeed;//ת���ٶ�
	float									autoSpeed;//�Զ����Ƶ��ٶ�
	float									modalRadius;//ģ�Ͱ뾶
	float									sightRadius;//��Ұ�뾶
	float									attackRadius;//�����뾶

	float									timeForResurrection;
	float									timeForAttack;
	float									timeForRun;

public:
	Character();
	~Character();


	void setControlByUser(bool userCon);
	void setPosition(D3DXVECTOR3);
	void setPositonChange(float x, float y, float z);
	void setFacing(float);
	void setScaling(float);
	void setWalkSpeed(float wSpeed);
	void setRunSpeed(float rSpeed);
	void setTurnSpeed(float tSpeed);


	void getPosition(D3DXVECTOR3 *);
	void getTargetPosition(D3DXVECTOR3 *);
	void getFacing(D3DXVECTOR3* pV);//ͨ�������ľ�����ת��3D�����������Ͷ��ص�w = 1��
	float getScaling();
	float getWalkSpeed();
	float getRunSpeed();
	float getTurnSpeed();
	int getCurrentTrack();//��õ�ǰ���
	int getCurrentAnim();//��õ�ǰ�Ķ���

	DWORD GetAnimIndex(char Index[]);//��ö�������


	virtual void Character::Init(LPDIRECT3DDEVICE9	p_d3dDevice, Direct3DInput * p_Input, Terrain * p_Terrain, Camera * p_Camera, std::vector<Character * > * p_Character);

	void CharacterInit(LPDIRECT3DDEVICE9	p_d3dDevice, 
		Direct3DInput * p_Input, Terrain * p_Terrain, Camera * p_Camera, 
		std::vector<Character * > * p_Character,
		LPCWSTR filename,//LPCWSTR��һ��ָ��unicode�����ַ�����32λָ�룬��ָ���ַ�����wchar�ͣ�wchar_t��C/C++���ַ��������ͣ���һ����չ���ַ��洢��ʽ��
		char * walkAnim, char * runAnim, char * idleAnim, char * attackAnim,
		float xRotation, float yRotation, float zRotation, float scal);


	virtual void Control(float f_TimeDelta);
	void UserControl();
	void AutoControl();

	virtual void Update();
	void ChangeTrack(DWORD name);//�ı���
	virtual void Draw();//����

	void Walk();
	void Run();
	void Idle();
	void Attack();

	bool BeingBlocked();//�Ƿ�ײǽorײ��

};