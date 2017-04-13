#include <iostream>
using namespace std;

class Command  //command class
{
public:
virtual void execute()=0;
};

class Light() 	//reciver class
	{
	public:
	void on() {cout<< "Light is on \n";}  //action method
	void off() {cout<< "Light is off \n"}
	}
class LightOnCmd: public Command  //action_1 impliment class
{
Light *lit;
public:
	LightOnCmd(Light *l): lit(l) {}
	void execute()
		{
		lit->on();
		}
};
class LightOffCmd: public Command  //action_2 impliment class
{
Light *lit;
public:
	LightOffCmd(Light *l): lit(l) {}
	void execute()
		{
		lit->off();
		}
};

class RemoteControl  //invoker class 
	{
	Command *m_cmd;
	public:
	void setCommand(Command *cmd)
		{
		m_cmd= cmd;
		}
	void buttonPress()
		{
		m_cmd->execute();
		}
	};

int main()
{
Light *light= new Light;  

LightOnCmd *LightOn= new LightOnCmd(light);
LightOffCmd *LightOff= new LightOffCmd(light);

RemoteControl *control= new RemoteControl;
control->setCommand(LightOn);
control->setCommand(LightOff);
control->buttonPress();

delete light, LightOn, LightOff, control;
return 0;
}






