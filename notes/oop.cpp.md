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
    · 类里面有两个内容，年龄和名字，叫做类的成员数据，或者叫做属性，类比int a =10, 10就是a的属性 
+++

## 3.公有和私有

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
  
* name 公有
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
	  
	  //下面主函数
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
        void ptint_name();  //这个print名字是公有的方法
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
· 核心思想：==通过公有方法的外壳调用私有方法==
· 修改后的例子

```
class student  //类定义，没写全，为了突出重点忽略了构造函数
{
pubilc:
	void print_age_pubilc();  //这个print_age_public是公有的方法，外面可以看到
private:
	void print_age_private();  //这个print_age_private是私有的方法，外面看不到
}

void student :: print_age_pubilc()  //定义公有方法print_age_pubilc
{
	print_age_private();  //==注意：这里通过公有方法的外壳调用私有方法==
}

void student :: print_age_private()  //定义print_age_private私有方法
{
	cout<<"20";  //打印出20
}

//以下是主函数
student aa;  //创建对象aa（ps: 省略了构造函数）
aa.print_age_pubilc();  //这里通过公有方法的外壳，调用私有，然后打印出20
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
  class undergraduate : public student   //本科生类定义，冒号后面表示从student类公有派生而来
  {
  public:
  	string course;  //这行新增定义了一个公共的字符串属性course，比如本科生的大学物理课程
  }
  ```

* 派生出研究生的写法

```
class postgraduate : public student  //研究生类定义，冒号后面表示从student类公有派生而来
{
pubilc:
	string research;  //这行新增定义了一个和本科生不一样的字符串属性research，比如研究的方向：芯片设计
}

//下面是主函数
postgraduate bb;  //创建研究生对象，此时子类无构造函数，系统将调用父类student无参数的构造函数给name和age赋一默认值，其默认值为“张三”，age = 20
bb.set (25);  //postgraduate本身没有set方法，这里调用父类student的方法，对age赋值
```

* 对比研究生和本科生两个类：
· 都没写两个基本属性name和age，因为根本不用写，==子类自动继承父类的属性和方法==
· 除了公有的name和age，也有不同的东西，这是非常重要的类的派生特性，除了继承而来，还能有自己的属性和方法

### (2)类在不同情况下的继承（公有/私有/保护 继承）

* public, private, protect（保护）
· 他们三个是平级的
· 在没有派生继承的情况下，protect 和 private 的效果完全一样

* 研究生类定义：
· class postgraduate : pubilc student {···}
· 其中public表示公有继承，只继承student的公有部分（age和name），并且age和name也将作为研究生类的public部分
· 研究生类无法继承也无法访问student类的私有部分
* 将父类student类定义的private替换为protect

​       · 对student本身无任何变化
​       · 当class postgraduate : public student {···}时候，除了public被继承了，protect（私有）也被研究生继承了
​       · student的protect内容被继承到了postgraduate的protect中

* 公有继承：
· 父类student， public内容A, private内容B， 子类postgraduate公有继承，则只有public内容A
· 父类student， public内容A, protect内容B， 子类postgraduate公有继承，则有public内容A + project内容B

* 私有继承和保护继承
· class postgraduate ：private student  /  class postgraduate ：protect student
· 父类student， public内容A, private内容B，子类私有继承，则子类只有内容A，且为private
· 父类student， public内容A, protect内容B，子类保护继承，则子类有内容A 和 B, 且均为protect
· 在保密优先级上，private最为私密，protect其次，public最公开。private里面的内容无论如何都不能被继承

### (3)子类的构造函数

* 子类可以有自己的构造函数
· 子类没有自己的构造函数，系统会调用父类student的构造函数
· 无论子类有没有自己的构造函数，创建子类对象时，父类构造函数都将被调用
* 研究生类不带参数构造

```
class postgraduate : public student  //研究生类定义，表示从student中派生而来
{
public:  //研究生的公有成员
	string research;  //新增定义了一个公开的属性research，字符串，研究方向
	postgraduate();  //无参数的构造函数申明
	postgraduate(int a, string b, string c);  //带参数的构造函数申明，参数为年龄 姓名 研究方向 
}

postgraduate :: postgraduate();  //无参数的构造函数定义
{
	research = "asic design";  //对研究生的research属性赋值为asic design,==注意没有age和name==
}

//下面是主函数
postgraduate bb;  //创建研究生对象bb，调用无参数构造函数

```

· 创建子类bb对象时，系统首先自动运行父类student构造函数，对age和name赋值，随后运行子类postgraduate构造函数，对bb对象进行拓展，增加research内容
· 子类是不能继承父类的构造函数的，只能调用父类构造函数

* 研究生类带参数构造

```cpp
class postgraduate : public student  //研究生类定义，表示从student中派生而来
{
public:  //研究生的公有成员
	string research;  //新增定义了一个公开的属性research，字符串，研究方向
	postgraduate();  //无参数的构造函数申明
	postgraduate(int a, string b, string c);  //带参数的构造函数申明，参数为年龄 姓名 研究方向 
}

postgraduate :: postgraduate(int a, string b, string c) : student(a, b) //带参数的构造函数定义
{
	research = c;
}

//下面是主函数
postgraduate bb( 25, "李四" , "ASIC design");  //创建研究生对象bb，传入有参数的构造函数

```

· 程序会先调用父类student构造函数，把25和李四两个值传入父类student带参数的构造函数
· 随后把参数 c = ASIC design 传入bb自己的research属性
==注意：==定义和申明与无参数构造有所不同

## 3.多态

### (1)python等新兴语言中的多态
* 举个小例子
  我们都知道：
  int a = 1; int b = 2; 则我们可以得到 a+b=3；
  => 加法专属于整数类的，如果是 string a; string b; 显然是不能用加法的（char a + char b 可以） 
  （方法真的是专属于某一个类吗？）

  ==But！！！==
  在比较新的编程语言中，如 python/ruby，两个字符串是可以相加的，
  eg:
  
  ```
    a = "xxxx";        #这是python无需定义数据类型
    b = "yyyyy";
    print (a+b);         #会打印出xxxxyyyyy
  ```
  
 * 这就是面向对象编程（python）中的“多态”
   
   
   · 不太严谨的说法是：不同类的对象可以用相同的方法，即有相同的方法名字，但方法里面的内容具体干了什么，是不一样的（eg: 当 a  和 b 是数字时，符号“+”， 执行传统意义上的加法； 当 a 和 b 是字符串时，符号“+”， 执行字符串的拼接， 系统会根据当前情况智能选择  采用哪种方法） => ==在python等新兴语言中是正确的==
   

### (2)C++中的多态
#### a.实现相同函数名执行不同内容的三种方法
   1. 重载
       ~ python a+b 这个例子中，C++中看上去更接近重载
       ~ 重载两个函数参数格式必须是不一样的（编译器可以识别出来）
       ~ 不依赖与面向编程，依赖编译器

     ```cpp
     class student
     {
     public:
      int age;
      string name;
      bool set (int a); //两个函数名一样，但输入格式不一样
      bool set (string a); //这个函数定略过，name = a; return true;
     }
     ```


   2. 隐藏
      ~ 在父类student和子类postgraduate中都定义一个函数study(),输入参考格式相同不同都可以

   ```cpp
   class student  //类定义，没写全，为了突出重点忽略了构造函数和属性
   {
   public:
   		void study (bool a)  {cout<<"好好学习"};
   }
   
   class postgraduate : public student   //类定义，没写全，为了突出重点忽略了构造函数和属性
   {
   pubic:
   		void study (int b)  {cout<<"芯片设计"}; 
   }
   
   //下面是主函数
   postgraduate bb;  //子类对象
   student aa;   //父类对象
   bb. study( 2 );   //研究生对象调用研究生的study方法，参数为int，打印出芯片设技
   aa. study( true );  //学生对象调用学生的study方法，参数为bool，打印出好好学习
   bb. study( true );  //这行出错，研究生对象，但参数为bool，本来应该重载父类的study方法，因为这时父类方法被隐藏了，系统找不到对应的方法，这是隐藏和重载的区别
   
   ```

   3. 覆盖（override,又叫重写，这是C++的多态，后面讲）
#### b.类的指针（C++多态实现依赖于类指针）
* 不考虑继承，类指针与结构体指针类似

```cpp
student *p;   //新建一个student类指针
student aa;   //新建aa对象

p = &aa;     //p指针指向aa对象
p -> name;   //这个就和aa.name一样，返回aa的name值
p -> study();   //这个相当于aa.study(),对aa执行成员函数
```


~ 实际程序中使用更高级的写法

```c++
student *p = new student(20,"张三");
delete p;   //调用析构函数
```

* 考虑继承
~ 类定义忽略，且只考虑公有继承

```cpp
student *p1;   //新建一个student父类指针
postgraduate *p2;   //新建一个postgraduate子类指针

student aa;     //新建父类对象aa
postgraduate bb;    //新建子类对象bb

p1 = &aa;      //父类指针指向父类对象，可以
p2 = &bb;      //子类指针指向子类对象，可以
p1 = &bb;      //父类指针指向子类对象，可以
p2 = &aa;      //子类指针指向父类对象，会报错

```

~ 父类指针可以指向子类成员
· 因为研究生一定属于学生
· 但是反过来，学生一定属于研究生，这是不对的
· 注意：p1 -> research 会报错
· 虽然父指针指向了postgraduate，但不能调用postgraduate中的属性和方法；父类指针指向子类对象时，仍只能用父类中的方法

### c.真正的多态与虚函数

```c++
//下面是学生
class student    //学生类的定义，为了突出重点省略了构造函数和其他属性
{
public:
	virtual void study();   //声明study方法，注意前面加了virtual，是个虚拟函数，并且没有参数
}

void student :: study ()    //注意这里没有virtual，长的和普通成员一样
{cout<<"好好学习";}       //学生类没有具体的学习内容，只有好好学习


//下面是研究生
class postgraduate : public student   //研究生类的定义，为了突出重点省略了构造函数和属性，从student中派生而来
{
public:    //研究生的公有成员
virtual void study();    //声明study方法，注意前面加了virtual，是个虚拟函数，并且没有参数
}

void postgraduate :: study ()    //注意这里没有virtual，长的和普通成员一样
{cout<<"芯片设计";}     //研究生学习芯片设计


//下面是本科生
class undergraduate : public student   //本科生类的定义，为了突出重点省略了构造函数和属性，从student中派生而来
{
public:    //本科生的公有成员
virtual void study();    //声明study方法，注意前面加了virtual，是个虚拟函数，并且没有参数
}

void undergraduate :: study ()    //注意这里没有virtual，长的和普通成员一样
{cout<<"大学物理";}     //本科生学习大学物理


//下面是主函数
student aa;           //学生对象
postgraduate bb;      //研究生对象
undergraduate cc;     //本科生对象

student *p;       //定义父指针，学生类指针

p = &aa;         //父类指针指向父类学生对象
p -> study();    //调用学生类的study方法，打印出好好学习

p = &bb;         //父类指针指向子类研究生对象
p -> study();    //父类指针调用子类研究生类的study方法，打印出芯片设计，==就是多态==

p = &cc;         //父类指针指向子类本科生对象
p -> study();    //父类指针调用子类本科生类的study方法，打印出大学物理，==就是多态==

```

* 分别在student，postgraduate，undergraduate建立一个方法
~ 都叫study，且他们输入参数都一样，但每个study内容是不一样的
~ 在所有子类父类study声明前面加上关键字==virtual==，表示这是一个==虚函数==
* C++多态的核心：只要在程序开始的时候设置一个父类指针，之后这个指针可以动态的指向不同的类，并且指针还可以动态调用不同类的方法，从而实现了不同数据类使用相同的方法，重载是编译时决定，多态是运行时决定

### d.纯虚函数与抽象类

* 抽象类

~ 学生是一个类，研究生、本科生、中小学生都是它的子类
~ 现实中，如果一个学生叫张三，那张三一定是研究生、本科生或者中小学生中的一员
~ 单纯只属于学生类，而不属于任何一个子类的对象张三在现实中是不存在的
~ 学生类不应该具有自己的对象，于是学生类被叫做抽象类

~设置依赖纯虚函数，形式如下：

```c++
class student     //学生类定义
{
public:
	student ();        //抽象类也是有构造函数的
	student (int a, string b);    //构造函数重载
	virtual void study () = 0;    //声明study方法，注意加了virtual和0，表明这是纯虚函数
}

//下面是主函数
student aa;    //这里报错，不允许创建抽象类对象
student *p;    //可以创建抽象类指针
postgraduate bb;      //创建子类对象
p = &bb;        //父类指针指向子类
p -> study();        //通过多态调用子类的study方法

```

~ 当设置了virtual void study () = 0;后
  · student就是一个抽象类
  · study()函数只有声明，没有定义，其具体内容靠子类的多态实现
  · 依然可以创建一个student的指针，但不能创建student对象了