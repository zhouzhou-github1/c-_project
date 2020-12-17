/*************************************************
 *文件名：main.cpp
 *描  述：C++继承与派生学习
 *作  者：冯洲
 *时  间：2020.12.05:20.06
 *************************************************/

#include <iostream>
#include <string>
#include <vector>
#include "hero.h"		//使用<>打不开hero.h
#include "Warrior.h"
#include "Archmage.h"
#include "Teacher.h"
#include "GameCore.h"
#include "Assassin.h"

using namespace std;


void HeroTest();
void WarriorTest();
void AttackTest();
void TeacherTest();
void GameCoreTest();

int main()
{
	cout << "--------------------全  军  出  击--------------------" << endl;
//	HeroTest();
//	WarriorTest();
//	AttackTest();
//	TeacherTest();
	GameCoreTest();
	return 0;
}

void HeroTest()
{
	hero hero1;
	cout << hero1 << endl;
	hero1.Move();
	cout << endl;
	hero *hero2 = new hero("测试英雄2", 999, 5000, 5000);
	cout << *hero2 << endl;
	hero2->Move();			//等价方式   (*hero2).Move();

	delete hero2;
}

void WarriorTest()
{
	//创建派生类对象时，会先调用基类构造，再调用派生类构造
	//析构时，先调用派生类析构，再调用基类析构
	Warrior warrior1;
	//子类对象
	//情况1:派生类不实现Move方法，默认调用基类实现
	//情况2:派生类实现Move方法，那么就会调用派生类实现
	warrior1.Move();			//派生类中如果不实现Move方法，默认调用基类hero中的Move方法

	hero *hero3 = new Warrior();		//基类指针指向派生类---标准的多态
	hero3->Move();						//调用的是基类实现   ****若要调用子类实现---虚函数***
	delete hero3;

	Warrior warrior2("诸葛亮", 11);
	hero& refHero = warrior2;			//如果使用基类引用指向派生类对象，那么基类引用就不能调用派生类中定义的方法
	hero* ptrHero = &warrior2;			//如果使用基类指针指向派生类对象，那么基类引用就不能调用派生类中定义的方法
	//除非进行强制转换
//	Warrior& warrior3 = refHero;	直接这样转不行
	Warrior& warrior3 = (Warrior &)refHero;		//父类引用强转为子类引用或指针
}

void AttackTest()
{
	Warrior warrior2("曹操", 50);
	Warrior warrior3("吕布", 60);
	cout << "--------------------生成第一个英雄--------------------" << endl;
	cout << warrior2 << endl;
	cout << "--------------------生成第二个英雄--------------------" << endl;
	cout << warrior3 << endl;
	cout << "--------------------开  始  对  战--------------------" << endl;
	warrior2.XiaoQuanQuan(warrior3);
	cout << "--------------------生成第三个英雄--------------------" << endl;
//	Archmage  *archmage1 = new Archmage("貂蝉", 55);	
//	攻击时(*archmage1).BiuBiuBiu(warrior3);    archamage1->BiuBiuBiu(warrior3);这样是错误的：无法将参数 1 从“Archmage *”转换为“Warrior &”
	Archmage archmage1("貂蝉", 55);
	cout << "--------------------家  暴  现  场--------------------" << endl;
	(archmage1).BiuBiuBiu(warrior3);			
	warrior3.XiaoQuanQuan(archmage1);
	cout << "小三参与打架啦!!!二打一了。" << endl;
	warrior2.XiaoQuanQuan(warrior3);
	(archmage1).BiuBiuBiu(warrior3);
	(archmage1).BiuBiuBiu(warrior3);
	cout << "--------------------战  斗  结  束--------------------" << endl;
	cout << "--------------------曹操当前状态！--------------------" << endl;
	cout << warrior2 << endl;
	cout << "--------------------吕布当前状态！--------------------" << endl;
	cout << warrior3 << endl;
	cout << "--------------------貂蝉当前状态！--------------------" << endl;
	cout << archmage1 << endl;

	Archmage * archmage2 = new Archmage("小乔", 66);
	(*archmage2).BiuBiuBiu(archmage1);
//	archmage2->BiuBiuBiu(archmage2);
	warrior2.XiaoQuanQuan(*archmage2);
	(*archmage2).BiuBiuBiu(archmage1);
}
/**********************************************
 *错误error:C2061:语法错误
 *错误原因：子类A中包含了B，子类B中又包含了A
 *解决办法：在A.h文件中声明B类(class B;),在A.cpp文件中include "B.h";
 *			在B.h文件中声明A类(class A;),在B.cpp文件中include "A.h";
 *使用目的：进行子类间的调用，例如刺客攻击法师等等
 **********************************************/


void TeacherTest()
{
	Teacher teacher1(8000);
}

void GameCoreTest()
{
	hero hero1("布衣英雄");
	Warrior warrior1("吕布", 55);
	Archmage archmage1("貂蝉", 80);
	//hero1.Move();				//实际中一般不这样调用，都是把Move封装成一个类
	//warrior1.Move();
	//archmage1.Move();


	GameCore gameCore;				//定义的移动类
/*与GameCore.h中一同

	//一个简单的多态		静态的多态的优点：编译速度快，运行效率高、缺乏灵活性
	gameCore.MoveRole(warrior1);
	gameCore.MoveRole(archmage1);
	gameCore.MoveRole(hero1);

	cout << "--------------------动  态  多  态--------------------" << endl;
	Warrior warrior11("吕布", 55);
	Warrior warrior12("夏侯惇", 55);
	Warrior warrior13("程咬金", 55);
	Warrior warrior14("凯", 55);
	Warrior warrior15("无敌飓风号", 55);
	vector<Warrior*> vecWarrior;
	vecWarrior.push_back(&warrior11);
	vecWarrior.push_back(&warrior12);
	vecWarrior.push_back(&warrior13);
	vecWarrior.push_back(&warrior14);
	vecWarrior.push_back(&warrior15);
	//主要观察：调用游戏业务方法来统一操作传入的多个战士

	gameCore.MoveRole(vecWarrior);

*/

	//cout << "--------------------测试使用virtual--------------------" << endl;
	gameCore.MoveRole(hero1);
	gameCore.MoveRole(warrior1);			//如果基类中不添加virtual关键字
	gameCore.MoveRole(archmage1);			//编译器就会根据当前对象的类型调用基类中定义的Move方法

	Assassin assa("飞檐走壁韩信", 50);
	gameCore.MoveRole(assa);

	warrior1.XiaoQuanQuan(archmage1);
	warrior1.XiaoQuanQuan(assa);

	cout << "--------------------测试向上转换--------------------" << endl;
	Archmage warrior10;
	hero & hero10 = warrior10;
	Warrior & newWarrior10 = (Warrior&)warrior10;		//能执行，但是不安全。会让法师变成战士
	newWarrior10.XiaoQuanQuan(assa);
}

