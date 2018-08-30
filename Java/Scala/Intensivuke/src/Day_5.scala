

object Day_5 extends App {
  
  abstract class SuperClass{
    def someMethod() = {
      println("hi");
    }
  }
  
  class SubClass extends SuperClass{
    override def someMethod() = {
      println("hi");
    }
  }
  
  trait Philosophical
  {
    def philosophize(){
      println("cogito ergosum");
    }
  }
  
  trait Animal
  {
    def heartbeat(){println("beating heart");}
    
    def philosophize(){
      println("cogito ergosum");
    }
    
  }
  
  class Frog extends Philosophical with Animal
  {
    override def toString = "green";
    override def philosophize(){println("cogito ergosum");}//Forhindrer konflikt mellom traits.
    def liveAndPhilosophize()
    {
      this.philosophize();
      this.heartbeat();
    }
  }
  
  class Cat extends Philosophical
  {
    override def toString = "orange";
  }
  
  val f = new Frog();
  f.philosophize();
  f.heartbeat();
  
  //val c = new Cat() with Animal;
  //c.philosophize();
  
  class Lightsaber
  {
    def properties:List[String] = List();
    override def toString = "It's a"+properties.mkString(" ",","," ")+"lightsaber";
  }
  
  trait Red extends Lightsaber
  {
    override def properties() = super.properties :::List("red");
  }
  
  trait Crossguard extends Lightsaber
  {
    override def properties() = super.properties :::List("crossguard");
  }
  
  trait Dual extends Lightsaber
  {
    override def properties() = super.properties :::List("dual");
  }
  
  val mySaber = new Lightsaber() with Red with Crossguard with Dual;
  println(mySaber);
  
  println("__________________________________________________________")
  
  abstract class Vehicle{}
  
  class Car extends Vehicle with Wheel with SteeringWheel
  {
    def Drive()
    {
      run();
      steer();
    }
  }
  
  trait Wheel{def run(){println("running");}}
  
  trait SteeringWheel{def steer(){println("steering");}}
  
  val myCar = new Car()
  myCar.Drive();
  
  println("__________________________________________________________")
  
  //Extractor
  
  object Email
  {
    def apply(user:String,domain:String) = user+"@"+domain;
    def unapply(str:String):Option[(String,String)] = {
      var parts = str split "@";
      if(parts.length==2) Option(parts(0),parts(1))
      else None;
    }
  }
  
  def workAtUiA(s:String):Boolean = s match{
    case Email(_,"uia.no") => true;
    case _ => false;
  }
  
  println(workAtUiA("morten.goodwin@uia.no"));
  println(workAtUiA("mortengoodwin@gmail.no"));
  
  println("__________________________________________________________")
  
  //Lazy vals
  
  class Demo
  {
    lazy val x = {println("Initializing x");"done"}
  }
  
  val d = new Demo();
  println("Before");
  println(d.x);
  
  class Demo2
  {
    lazy val x = {(1 to 1000).toList;}
  }
  val d2 = new Demo2();
  for(i <- d2.x)
  {
    println(i);
  }
  
  
  
  //END
}