# DesignPattern
## 1. 定义
```asm
设计模式:
是一套被反复使用的、多数人知晓的、经过分类编目的、代码设计经验的总结。
使用设计模式是为了重用代码、让代码更容易被他人理解、保证代码可靠性。 
毫无疑问，设计模式于己于他人于系统都是多赢的，设计模式使代码编制真正工程化，设计模式是软件工程的基石，如同大厦的一块块砖石
项目中合理地运用设计模式可以完美地解决很多问题，每种模式在现实中都有相应的原理来与之对应，每种模式都描述了一个在我们周围不断重复发生的问题，以及该问题的核心解决方案，这也是设计模式能被广泛应用的原因。
```
## 2. 设计原则
#### **1). 开闭原则（Open Close Principle）**
```asm
对扩展开放，对修改关闭。
在程序需要进行拓展的时候，不能去修改原有的代码，实现一个热插拔的效果; 简言之，是为了使程序的扩展性好，易于维护和升级。
想要达到这样的效果，我们需要使用接口和抽象类.
```

#### 2). 里氏代换原则（Liskov Substitution Principle）**
```asm
里氏代换原则是面向对象设计的基本原则之一
里氏代换原则中说，任何基类可以出现的地方，子类一定可以出现
LSP 是继承复用的基石，只有当派生类可以替换掉基类，且软件单位的功能不受到影响时，基类才能真正被复用，而派生类也能够在基类的基础上增加新的行为
里氏代换原则是对开闭原则的补充。实现开闭原则的关键步骤就是抽象化，而基类与子类的继承关系就是抽象化的具体实现，所以里氏代换原则是对实现抽象化的具体步骤的规范
```

#### 3). 依赖倒转原则（Dependence Inversion Principle）
```asm
这个原则是开闭原则的基础，具体内容：针对接口编程，依赖于抽象而不依赖于具体。
```

#### 4). 接口隔离原则（Interface Segregation Principle）
```asm
使用多个隔离的接口，比使用单个接口要好。
它还有另外一个意思是：降低类之间的耦合度。
由此可见，其实设计模式就是从大型软件架构出发、便于升级和维护的软件设计思想，它强调降低依赖，降低耦合。
```

#### 5). 迪米特法则，又称最少知道原则（Demeter Principle）
```asm
最少知道原则是指：一个实体应当尽量少地与其他实体之间发生相互作用，使得系统功能模块相对独立。
```

#### 6). 合成复用原则（Composite Reuse Principle）
```asm
合成复用原则是指：尽量使用合成/聚合的方式，而不是使用继承
```

## 3. 模式分类
 
模式分类 | 描述 | 包括
---|---|---
创建型模式 | 创建对象的同时隐藏创建逻辑；<br>不使用 new 运算符直接实例化对象 | - 工厂模式（Factory Pattern）<br> - 抽象工厂模式（Abstract Factory Pattern）<br>- 单例模式（Singleton Pattern）<br>- 建造者模式（Builder Pattern）<br>- 原型模式（Prototype Pattern）
结构型模式 | 关注类和对象的组合 | - 适配器模式（Adapter Pattern）<br>- 桥接模式（Bridge Pattern）<br>- 组合模式（Composite Pattern）<br>- 装饰器模式（Decorator Pattern）<br>- 外观模式（Facade Pattern）<br>- 享元模式（Flyweight Pattern）<br>- 代理模式（Proxy Pattern）
行为型模式 | 关注对象之间的通信 | 	- 责任链模式（Chain of Responsibility Pattern）<br>- 命令模式（Command Pattern）<br>- 解释器模式（Interpreter Pattern）<br>- 迭代器模式（Iterator Pattern）<br>- 中介者模式（Mediator Pattern）<br>- 备忘录模式（Memento Pattern）<br>- 观察者模式（Observer Pattern）<br>- 状态模式（State Pattern）<br>- 空对象模式（Null Object Pattern）<br>- 策略模式（Strategy Pattern）<br>- 模板模式（Template Pattern）<br>- 访问者模式（Visitor Pattern）
J2EE 模式 | 关注表示层 | - MVC 模式（MVC Pattern）<br>- 业务代表模式（Business Delegate Pattern）<br>- 组合实体模式（Composite Entity Pattern）<br>- 数据访问对象模式（Data Access Object Pattern）<br>- 前端控制器模式（Front Controller Pattern）<br>- 拦截过滤器模式（Intercepting Filter Pattern）<br>- 服务定位器模式（Service Locator Pattern）<br>- 传输对象模式（Transfer Object Pattern）

### 1) 创建型模式
#### 1. SimpleFactory Pattern
```asm
简单工厂模式:
定义一个简单工厂类，它可以根据参数的不同返回不同类的实例，被创建的实例通常都具有共同的父类
```
![简单工厂模式](http://i2.tiimg.com/738210/0243bf29e113e9bf.png)

#### 2. Factory Pattern
```asm
工厂模式:
定义一个用于创建对象的接口，但是让子类决定将哪一个类实例化。工厂方法模式让一个类的实例化延迟到其子类
```
![工厂模式](http://i2.tiimg.com/738210/6c25b1a76d1f434e.png)

#### 3. AbstractFactory Pattern
```asm
抽象工厂模式:
提供一个创建一系列相关或相互依赖对象的接口，而无需指定他们具体的类。
```
![抽象工厂模式](http://i2.tiimg.com/738210/9b45176135648761.png)

#### 4. Singleton Pattern
```asm
单例模式:
确保一个类只有一个实例，并提供一个全局访问点来访问这个唯一实例。
```
![单例模式](http://i2.tiimg.com/738210/8496b7378726243c.png)

#### 5. Builder Pattern
```asm
建造者模式:
将一个复杂对象的构建与它的表示分离，使得同样的构建过程可以创建不同的表示
```
![建造者模式](http://i2.tiimg.com/738210/5320680937849071.png)

### 2). 结构型模式
#### 1. Adapter Pattern
```asm
适配器模式：
将一个类的接口转换成客户希望的另一个接口。适配器模式让那些接口不兼容的类可以一起工作
```
![适配器模式](http://i2.tiimg.com/738210/ed1d134a5d99ce44.png)

