#pragma once

#include "../Base/PlayerBase.h"


class Witch : public PlayerBase
{
public:
    Witch();
    virtual ~Witch();

    void Init();// ������
    void End();// �I������
    void Update();// �X�V����
    void Draw();// �`�揈��
private:
    int m_handle;// �v���C���[�̉摜
    
    int m_imgSizeX;
    int m_imgSizeY;

    int m_imgX;// X�̃A�j���[�V����
    int m_imgY;// X�̃A�j���[�V����


};

