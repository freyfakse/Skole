

object Day_1 extends App {
  
  /*
  
  println("Hello world");
  
  val a = 3.5f;//float
  val b = 3.5; //double
  val c = 'c'; //char
  val d = "Hi"; //String
  val e = """Ho
    in
    many
    rows""";
  val f = """ Text with "quotation" """;
  val g = 'symbol;
  println(1==1);
  println(1==1.0);
  
  def max(x:Int,y:Int):Int = {
    if(x>y) return x;
    return y;
  }
  println("max "+max(2,3));
  
  def max2(x:Int,y:Int) = {if(x>y)x else y;}
  
  println("max2 "+max2(5,8));
  
  var y =0;
  
  def setValue(x:Int):Unit = {y=x}
  
  println(y);
  setValue(5);
  println(y);
  
  def greet() = println("Hello world");
  greet();
  
  def i():Int = {return 2;}
  def j = 2;
  
  val s = "Hi class";
  println(s.indexOf('c'));
  println(s indexOf 'c');
  println(s indexOf ('c',1));
  println(5+4);
  println(5.+(4));
  
  def sqrt(x:Double) = {
    
    if(x>0)
    {
      java.lang.Math.sqrt(x);
    }
    else
    {
      "Cannot sqrt a negative number."
    }
    
  }
  
  println(sqrt(2.2));
  println(sqrt(-2.2));
  
  
  var arr = Array("Luke","Leia","Han"); //Array
  var i=0;
  
  while(i<arr.length)
  {
    println(arr(i))
    i = i+1;
  }
  
  for(arg <- arr)
  {
    println(arg);
  }
  
  for(i<-0 to 2)
  {
    println(arr(i));
  }
  
  arr.foreach((arg:String) => println(arg));
  
  
  var arr2 = Array(1,6,2);
  var x= 0;
  
  for(i<-arr2)
  {
    if(i>x)
    {
      x=i;
    }
  }
  println(x)
  
  
  def inc(x:Int):Int = {return x+1;}
  def applyToInt(f:(Int=>Int),i:Int):Int = {return f(i);}
  println(applyToInt(inc,2));
  
  val arr3 = Array(0,2,4,6,8);
  def divi(x:Int):Int = {return x/2;}
  def hof(f:(Int=>Int),l:Array[Int]):Unit = {
    for(i<-l)
    {
      println(f(i))
    }
  }
  hof(divi,arr3);
  
  def p(x:String):Unit = {println(x)}
  
  arr.foreach(p);
  arr.foreach(println);
  
  //Lambda
  ((x:Int)=>println(x*x))(2);
  val l = List(1,1,2,3,5,4,8)
  l.foreach((x:Int)=>println(x*x))
  
  
  arr.foreach((s:String)=>println(s))
  
  
  
  val arr3 = Array(2.0,4.0,8.0);
  
  //ASSIGNMENT
  //1
  def avg(l:Array[Double]):Double = {
    var sum = 0.0;
    for(i <- l)
    {
      sum=sum+i;
    }
    var tot = sum/l.length;
    
    return tot;
  }
  println("Gjennomsnitt: "+avg(arr3));
  
  
  //2
  val arr = Array(1.0,2.0,3.0,4.0);
  
  def Median(l:Array[Double])= {
    val l2 = l.sortWith(_<_);
    val middle = l2.length/2;
    
    if(middle%2 ==0) 
    {
      var x=l(middle);
      var y=l(middle-1);
      var avg = (x+y)/2;
      println(avg);
    }
    else
    {
      println("Median: " +l2(middle));
    }
    
  }
  
  Median(arr);
  
  //val l = List(1,1,2,3,5,4,8)
  //l.foreach((x:Int)=>println(x*x))
  */
 
  
}