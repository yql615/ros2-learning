# 一、第一部分

## 1.什么是类（class）,什么是对象（obj）
* C语言：int a=10
· int 表示整数类，是系统自带的类，a是这个类的一个对象
· float , char 都是系统自带的类
* 面向对象编程
· **创建自己的类**
· **创建自己的对象** 
· 例如： 学生类  student, 对象 张三李四
+++

## 2.如何创建自己的类
* 形式：
  
  ```
    class student //这个大括号里的叫类定义
    {
        string name; //学生的名字
        int age; //学生的年龄
    }
  ```
  
    · 类名：student
    · 类里面有两个内容，年龄名字，叫做类的成员数据，或者叫做属性，类比int a =10, 10就是a的属性 
+++

## 3.共有和私有

* **在类的定义里，形式如：**
  
  ```
    class student //这个大括号里的叫类定义
    {
    public:
        string name;
    private:
        int age;
    }
  ```
  
* name 共有
 · 类的外部（主函数里或者其他类）可以读写name的值
* age 私有
 · 类的外部外面看不到
* 可以只有 pubilc
 · 可以将名字和年龄都写在public ,初学者可以先不写private
  · 没有private的类相当于结构体
+++

## 4.如何使用一个类
* 类被定义后，就创建类的对象，形式和 int a 一样
 · student aa;
  · 创建一个student类的对象，名字叫aa
  · aa.age=20;
  · 给aa的属性赋值，和结构体一样
+++

## 5.什么是成员函数
* 成员函数的重载
 · 和c语言普通函数一样，成员函数也可以重载
   · 不同函数可以有相同的函数名，通过不同的输入参数来识别，如：
  
   ```
   class student
   {
   public:
       int age;
       string name;
       bool set (int a); //两个函数名一样，但输入格式不一样
       bool set (string a); //这个函数定略过，name = a; return true;
   }
   ```
   
   

+++

# 二、第二部分

## 6.构造函数，自动初始化对象

* student aa, 创建aa对象， aa有默认值么?
 · 如果有构造函数，那么aa就有默认值

* 为什么要构造函数？
 · 建立一个对象aa，要给他的年龄和姓名分别赋值，那就要写两行代码 set ("张三")； set (20),使用构造函数后，即使你有再多成员数据，不用一一写了
  ==· 构造函数的本质即对象初始化==
  
* 构造函数的名字必须和类的名字一样
  
  
        class student    //类定义里申明构造函数
        {
        public:
            int age;
            string name;
            student ();   //这是构造函数，没有输入值和返回值，并且名字和类的名字一样
        }
        
        student ：：student()     //构造函数定义，特点就是冒号两边是一样的，注意这个函数没有输入值
        {
            age = 20;  //构造函数里，可以对全部的成员数据给一个默认值
            name = "张三"；
        }
        
        //下面是主函数
        student aa;      //新建一个student类的的对象，名字叫aa,这里不用再人工赋值 年龄和名字了，将自动调回构造函数给的年龄和名字默认值
    
    
+++

## 7.带参数的构造函数，动态初始化对象

* 前面的构造函数没有输入值，年龄只能是20，改进一下
	
	```
	class student    //类定义里申明构造函数
	{
	public:
	  	int age;
	  	string name;
	  	student ();  //这是没有参数的构造函数申明，允许几个名字一样的函数，通过不同输入值来区分
	  	student (int a,string b);  //同名函数构造申明，即重载，带2个输入参数，即名字和年龄
	}
	
	  student :: student(int a,string b)  //这是带参数的构造函数申明，大括号里是函数定义，前一个student代表类后一个代表构造函数
	  {
	  	age=a;  //这样名字就不是默认值了，可以动态输入
	  	name=b;
	  }
	  
	  //下面主函数***
	  student aa;   //新建一个student类的对象aa,自动给aa的属性填默认值
	  student bb(25,"李四")；  //构造函数重载，新建一个student类的的对象bb,同时动态输入名字和年龄
	
	```
	


+++

## 8.析构函数,销毁对象

+++

## 9.常构造函数const，只读不写

* 一个方法只读取属性，而不修改属性，就是常成员函数
	
	
	
        class student   //类定义，这里省略了构造函数
        {
        public:
            int age;
            string name;
            bool set (int  i);   //这个就是成员函数的申明，又叫方法
            bool read () const;  //右面加了const，表示这个函数只读不写
        }
        
        bool student :: read () const;
        {
            cout<<name;  //打印出姓名
            cout<<age;   //打印粗年龄
            return true;
        }
        
	    student aa;   //创建对象
	    aa.read();  //在创建aa后，调用read方法
	
	
	
* 实际上可以不使用const，普通方法也可以读取数据，加const只是为了安全起见，防止意外修改数据
* 更加不正规的做法是直接读取：aa.age, 在正规程序还是会在使用const来读取数据

+++

## 10.静态成员函数 ，静态成员数据，关键字static

### （1）静态成员数据
* 一个类可以创建多个对象，int a, int b, int c; int d   ··· 。student 类也可以不停创建新建 aa, bb, cc, dd 等多个对象
* 需要一个变量 cnt =4 来表示程序已经创建了4个对象了，cnt 这个数，与student类有关，但又不属于aa, bb, cc, dd 中间任何一个对象
* ==这种描述全局，又与某个对象属性无关的，叫做静态成员数据==
* 读取静态成员数据的方法 叫做==静态成员函数==

### （2）在类定义中加入静态成员数据，静态成员函数

    class student  //类定义
    {
    public:
        int age;  //成员数据，年龄
        string name;  //成员数据，名字
        student();  //没有参数的构造函数，创建对象时给 age, name 默认值
        static int cnt;  //static表示静态成员数据，统计有多少个对象
        static int count();  //static表示静态成员函数，返回有多少个对象
    }

### （3）如何定义静态成员

    student :: student()  //构造函数定义
    {
        age=20;  //构造函数里，可以对全部的数据给一个默认值
        name="张三";
        cnt=cnt+1;  //每次调用构造函数创建对象时，cnt加一，就可以统计出有多少对象了
    }
    int student ::count()  //静态成员函数的定义，注意这里不写static了
    {
        rentun cnt;  //返回静态成员数据，统计有多少对象
    }

### （4）如何使用静态成员函数，下面为主函数

    student aa;  //创建对象aa
    student bb;  //创建对象bb
    aa.count();  //调用count方法，返回静态成员数据 cnt = 2, 已建立两个对象，这行和下行是一样的
    bb.count();  //注意不论是aa还是bb，返回值都是一样的，静态成员数据不依赖某个对象
    student :: count();  //返回静态成员数据 cnt = 2, 这个写法和aa.count()效果完全一样，只有不依赖于对象的静态函数才可以这么写


+++

# 三、第三部分

## 1.类的封装

### (1).再谈 public 和 private

* 设 private 的目的
  · public的内容，可以在主函数看到，private内容只能在类的内部看到
  · 进阶：==对类的外部隐藏了类内部工作机制，即作为“封装”==
  · 小例子：

  ```
  class student  //类定义，没写全，为了突出重点忽略了构造函数和属性
    {
    public:  //共有部分
        void ptint_name();  //这个print名字是共有的方法
    private:  //私有部分
        void ptint_age();  //这个prin年龄是私有的方法
    }
  
    void student :: print_name()  //定义print名字公有方法
    {
        cout<<"张三";
    }
  
    void student :: print_age()  //定义print年龄私有方法
    {
        cout<<"20";
    }
  
    //以下是主函数
    student aa;  //创建的对象aa  (ps: 忽略了构造函数)
    aa.print_name();  //调用公有方法，打印出张三
    aa.print_age();  //调用私有方法，不允许，这行会报错，提示student类不存在print_age这个方法
    
  ```
  
* 既然私有方法不能被使用，那还有什么意义？
· 可以用，有条件
· 核心思想：==通过共有方法的外壳调用私有方法==
· 修改后的例子

```
class student  //类定义，没写全，为了突出重点忽略了构造函数
{
pubilc:
	void print_age_pubilc();  //这个print_age_public是共有的方法，外面可以看到
private:
	void print_age_private();  //这个print_age_private是私有的方法，外面看不到
}

void student :: print_age_pubilc()  //定义print_age_pubilc共有方法
{
	print_age_private();  //==注意：这里通过共有方法的外壳调用私有方法==
}

void student :: print_age_private()  //定义print_age_private私有方法
{
	cout<<"20";  //打印出20
}

//以下是主函数
student aa;  //创建对象aa（ps: 省略了构造函数）
aa.print_age_pubilc();  //这里通过共有方法的外壳，调用私有，然后打印出20
aa.print_age_private();  //这里出错，不允许直接调用私有方法

```



### (2)正规程序类定义的写法

* 之前讲的代码，以及之后讲的代码，都是为了举例说明，是“野路子的写法”。(ps: 后面讲的若无说明则仍全写在pubilc中)
* 正规写法

```
class student  //类定义
{

public:
	bool set (int a);  //两个函数名一样，但输入格式不一样
	bool set (string a);
	bool read () const;  //后面加了const，表示这个函数只读不写
	student ();  //不带参数的构造函数
	student (int a, string b);  //带参数的构造函数，动态赋值
	
private:
	int age;
	string name;
	
};
```

1. 一般把“方法”全部放到public中
2. “属性”放到private中
3. 目的是防止类的外部随意篡改数据
4. 通过函数来修改数据时，一般都具有防错机制，满足条件了才可以让你改


## 2.类的派生继承

### (1)什么是派生

* 把student类，细分成本科生和研究生
* 本科生和研究生也是学生，是学生的子类
* 学生是父类，也叫基类或者超累
* 所谓派生，是相对于父类而言的
* 所谓继承，是相对于子类而言的
* 派生出本科生的写法：

  ```
  class undergraduate : public student   //本科生类定义，冒号后面表示从student类共有派生而来
  {
  public:
  	string course;  //这行新增定义了一个公共的字符串属性course，比如本科生的大学物理课程
  }
  ```

  