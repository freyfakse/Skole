

object Day_4 extends App {

  /*
  
  class Rational(n:Int,d:Int){
    require(d!=0);
    val numer = n;
    val denom = d;
    println("Creating: "+n+"/"+d);
    override def toString = n +"/" + d;
    
    def +(that:Rational):Rational = {
      new Rational(numer*that.denom + that.numer*denom,denom*that.denom);
    }
    
    def *(that:Rational):Rational = {
      new Rational(numer*that.numer ,denom*that.denom);
    }
    
    def *(that:Int):Rational = {
      new Rational(numer*that ,denom);
    }
    
  }
  
  implicit def intToRational(n:Int):Rational = {
    return new Rational(n,1)
  }
  
  val r = new Rational(1,2);
  println(r);
  val r2 = new Rational(1,2);
  println(r2);
  val r3 = r + r2; //Samme som r.+(r2)
  println(r3);
  val r4 = r * r2; //Samme som r.*(r2)
  println(r4);
  val r5 = r*4;
  println(r5);
  val r6 = 4*r;
  
  //Program control
  val x = 12;
  val y = 14;
  /*
  var largest = 0;
  if(x>y)
    largest = x;
  else largest = y;
  */
  val largest =
    if(x>y) x;
    else y;
  println(largest);
  
  val l = List(1,2,3,4);
  for(i <- 1 to 4)
  {
    println(i);
  }
  
  val l2 = List(1,2,3,4);
  for(i <- 1 until 4)
  {
    println(i);
  }
  
  val l3=List(1,2,3,4,-2,-3)
  for(i<-l3 if i<3 if i>0)
  {
    println(l3)
  }
  
  val newlist =
    for(i<-l if i<3) yield i;
  println(newlist);
  
  val l4 = List("hi","hello","good day");
  val newlist2 =
    for(i<-l4 if i.startsWith("h")) yield i;
  println(newlist2);
  
  for(i <- 1 to 5)
    for(i<- 2 to 6)
      println("Runs many times")

  
  for(i1 <- 0 to 9)
  {
    for(i2 <- 0 to 9)
    {
      
      for(i3 <- 0 to 9)
      {
        
        for(i4 <- 0 to 9)
        {
          println(i1+""+i2+""+i3+""+i4)
        }
      }
    }
  }
  
  def getText(x:Int):String = {
    return x match {
      case 1 => "one";
      case 2 => "two";
      case 3 => "three";
      case _ => "Something else";
    }
  }
  
  println(getText(1));
  println(getText(11));
    
      
  def getText2(x:String):String = {
    return x match {
      case "bit" => "bot";
      case "bot" => "bit";
      case _ => "bitbot";
    }
  }
  
  println(getText2("bit"));
  println(getText2("bot"));
  println(getText2(""));
  
  sealed abstract class Expr;
  case class Var(name:String) extends Expr;
  case class Number(num:Double) extends Expr;
  case class Op(operator:String,left:Expr,right:Expr) extends Expr;
  
  val v = new Var("x");
  val op = Op("*",Var("x"),Number(1));
  
  def simplify(expr:Expr):Expr = {
    expr match{
      case Op("+",e,Number(0))=>e;
      case Op("*",e,Number(1))=>e;
      case Op("-",e,Number(0))=>e;
      case Op(op,l,r)=>Op(op,simplify(l),simplify(r));
    }
  }
  
  println(op);
  println(simplify(op));
  //println(simplify(new Op("*",Var("x"),Op("*",Var("x"),Number(1)))));
  
  def describe(expr:Expr):String = {
    expr match
    {
      case Number(_) => "A number"
      case Var(_) => "A variable"
    }
  }

  def pm(s1: Int, s2: Int, s3: Int, s4: Int): Int = {
    var l = List(s1, s2, s3).sortWith(_ < _);
    return l match {
      case List(1, 2, 3) => 4;
      case List(1, 2, 4) => 4;
      case List(1, 3, 4) => 4;
      case List(2, 3, 4) => 4;
      case List(_, _, _) => s4;
    }
  }

  def updateAllX() {
    for (x <- List(1, 2, 3, 4)) {
      for (y <- List(1, 2, 3, 4)) {
        val l = List(1, 2, 3, 4).filter(_ != y);
        val res = pm(
          getSquare(x, l(0)).getCorrectValue(),
          getSquare(x, l(1)).getCorrectValue(),
          getSquare(x, l(2)).getCorrectValue()
            getSquare (x, y).getCorrectValue());

        if (res > 0) {
          setValue(x, y, res);
        }
      }
    }
  }

  printit();
  updateAllX();
  printit();
  
  */
  
  //Assignments
  /*
  class Butikk()
  {
    def Epler() = {
      
    }
    def Bananer() = {
      
    }
    var le = List[Epler]();
    
    def getEple(eple:Epler):Epler = {
      
    }
    def setEple(eple:Epler) = {
      
    }
    def getBanan(banan:Bananer) = {
      
    }
    def setBanan(banan:Bananer) = {
      
    }
  }
  */
  
  def func(x:Int):String = {
    return x match{
      case 1 => "One";
      case 2 => "Two";
      case _ => "Other number";
    }
  }
  
  println(func(5));
  
  def func2(x:List[Int]):String = {
    return x(0) match {
      case 1 => "The list starts with 1";
      case _ => "Other number";
    }
  }
  val l = List(1,2,3,4);
  println(func2(l));
  
  
  
  //END
}