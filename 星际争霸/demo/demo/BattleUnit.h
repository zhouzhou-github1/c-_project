#pragma once
/*************************************************
 *�ļ�����BattleUnit.h
 *��  ����ѧϰ�麯����ս���൥λ   ����
 *��  �ߣ�����
 *ʱ  �䣺2020.12.15.20:30
 *************************************************/


class BattleUnit
{
public:
	BattleUnit();
	~BattleUnit();

	virtual void Fight(BattleUnit& unit);
	virtual void Move(int x, int y);
protected:

private:

};

