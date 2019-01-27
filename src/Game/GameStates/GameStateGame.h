#pragma once

#include "GameState.h"

#include <ShSDK/ShSDK.h>
#include "Players/IPlayer2EventListener.h"

class GameStateGame : public GameState, public IPlayer2EventListener
{

public:
	explicit			GameStateGame						(void);
	virtual				~GameStateGame						(void) SH_ATTRIBUTE_OVERRIDE;

	void				init								(void) SH_ATTRIBUTE_OVERRIDE;
	void				release								(void) SH_ATTRIBUTE_OVERRIDE;

	void				entered								(void) SH_ATTRIBUTE_OVERRIDE;
	void				exiting								(void) SH_ATTRIBUTE_OVERRIDE;

	void				obscuring							(void) SH_ATTRIBUTE_OVERRIDE;
	void				revealed							(void) SH_ATTRIBUTE_OVERRIDE;

	void				update								(float dt) SH_ATTRIBUTE_OVERRIDE;

	void				touchBegin							(const CShVector2 & pos, float ratio) SH_ATTRIBUTE_OVERRIDE;
	void				touchEnd							(const CShVector2 & pos, float ratio) SH_ATTRIBUTE_OVERRIDE;
	void				touchMove							(const CShVector2 & pos, float ratio) SH_ATTRIBUTE_OVERRIDE;

	//
	// IPlayer2EventListener interface
	virtual void		OnEventTypeAvailable				(Player2Event *pEvent) SH_ATTRIBUTE_OVERRIDE;
	virtual void		OnEventTypeUnavailable				(Player2Event *pEvent) SH_ATTRIBUTE_OVERRIDE;

	virtual void		OnEventTypeBegin					(Player2Event *pEvent) SH_ATTRIBUTE_OVERRIDE;
	virtual void		OnEventTypeEnd						(Player2Event *pEvent) SH_ATTRIBUTE_OVERRIDE;
	virtual void		OnEventTypeFinished					(Player2Event *pEvent) SH_ATTRIBUTE_OVERRIDE;

	virtual void		OnTypoGaugeUpdated					(float fNormedValue) SH_ATTRIBUTE_OVERRIDE;
	virtual void		OnTypoGaugeFilled					(void) SH_ATTRIBUTE_OVERRIDE;
	virtual void		OnTypoGaugeEmptied					(void) SH_ATTRIBUTE_OVERRIDE;

	virtual void		OnEventTypeTypeWordCharacterOK		(int iCharacterIndexOK) SH_ATTRIBUTE_OVERRIDE;
	virtual void		OnEventTypeTypeWordCharacterNOK		(int iCharacterIndexNOK) SH_ATTRIBUTE_OVERRIDE;

	virtual void		OnEventTypeRewardUserPireCoin		(int iPeerCoinAmount) SH_ATTRIBUTE_OVERRIDE;
	virtual void		OnEventTypeRewardUserHP				(int iHPBonus) SH_ATTRIBUTE_OVERRIDE;
	virtual void		OnEventTypeRewardGameSlowMotion		(float fSlowMotionFactor, float fDurationTime) SH_ATTRIBUTE_OVERRIDE;
	virtual void		OnEventTypeRewardTowerAttack		(int iBonusValue, float fDurationTime) SH_ATTRIBUTE_OVERRIDE;
	virtual void		OnEventTypeRewardTowerAttackSpeed	(int iBonusValue, float fDurationTime) SH_ATTRIBUTE_OVERRIDE;
	virtual void		OnEventTypeRewardTowerRadius		(int iBonusValue, float fDurationTime) SH_ATTRIBUTE_OVERRIDE;
	virtual void		OnEventTypeRewardTowerAttackAOE		(int iBonusValue, float fDurationTime) SH_ATTRIBUTE_OVERRIDE;

	virtual void		OnEventTypeMalusUserHP				(int iHPMalus) SH_ATTRIBUTE_OVERRIDE;
	virtual void		OnEventTypeMalusGameFastForward		(float iFastForwardFactor, float fDurationTime) SH_ATTRIBUTE_OVERRIDE;
	virtual void		OnEventTypeMalusGameNewEnemy		(int iEnemyCount) SH_ATTRIBUTE_OVERRIDE;
	virtual void		OnEventTypeMalusGameNewWave			(int iWaveCount) SH_ATTRIBUTE_OVERRIDE;
	virtual void		OnEventTypeMalusTowerAttack			(int iMalusValue, float fDurationTime) SH_ATTRIBUTE_OVERRIDE;
	virtual void		OnEventTypeMalusTowerAttackSpeed	(int iMalusValue, float fDurationTime) SH_ATTRIBUTE_OVERRIDE;
	virtual void		OnEventTypeMalusTowerRadius			(int iMalusValue, float fDurationTime) SH_ATTRIBUTE_OVERRIDE;
	virtual void		OnEventTypeMalusTowerAttackAOE		(int iMalusValue, float fDurationTime) SH_ATTRIBUTE_OVERRIDE;
protected:
private:
	static bool			OnGUIMenuClicked					(ShGUIControl * pControl, const CShVector2 & vPosition);
	static bool			OnGUIPauseClicked					(ShGUIControl * pControl, const CShVector2 & vPosition);
	static bool			OnGUIPlayClicked					(ShGUIControl * pControl, const CShVector2 & vPosition);
	static bool			OnGUIFastForwardClicked				(ShGUIControl * pControl, const CShVector2 & vPosition);
public:
protected:
private:
	ShGUIControlPanel *									m_pMainPanel;
	ShGUIControlText *									m_pWaveCurrent;
	ShGUIControlText *									m_pWaveTotal;
	ShGUIControlText *									m_pUserName;
	ShGUIControlText *									m_pMoneyValue;
	ShGUIControlText *									m_pHPValue;
	ShGUIControlText *									m_pMHPTotal;
	ShGUIControlRadioButton *							m_pPause;
	ShGUIControlRadioButton *							m_pPlay;
	ShGUIControlRadioButton *							m_pFastForward;
	ShGUIControlButton *								m_pMenu;
	CShArrayMap<EPlayer2EventType, ShGUIControlImage*>	m_amepModeImages;

	ShGUIControlEditBox *								m_pEditBoxHidden;

	ShGUIControlText *									m_pTextPopup;
};
