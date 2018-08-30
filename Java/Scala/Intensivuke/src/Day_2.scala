

object Day_2 extends App {
  
  /*
  
  def addTwo(x:Int,y:Int):Int = {return x+y;}
  
  class ATM(x:Int){
    var balance:Int =  x;
    def insert(nok:Int):Unit = {
      balance +=nok;
    }
  }
  
  var m1 = new ATM(0);
  println(m1.balance);
  m1.insert(4);
  println(m1.balance);
  
  
  class Square
  {
    var possibleValues = List(1,2,3,4);
    var solved = false;
    var boxValue = -1;
    var xNumber = -1;
    var yNumber = -1;
    
    def setValue(solution:Int) {
      this.possibleValues = List(solution);
      this.solved = true;
    }
  }
  
  var s1 = new Square();
  s1.boxValue=1;
  s1.yNumber=1;
  s1.xNumber=1;
  s1.setValue(1);
  
  var s2 = new Square();
  s2.boxValue=1;
  s2.yNumber=1;
  s2.xNumber=2;
  s2.setValue(1);
  
  
  class Square(boxNumber:Int,xNumber:Int,yNumber:Int,values:List[Int]=List(1,2,3,4),solved:Boolean=false)
  {
    val possibleValues = values;
    val x = xNumber;
    val y = yNumber;
    def setValue(solution:Int) = {
      new Square(this.boxNumber,this.xNumber,this.yNumber,List(solution),true);
    }
    
    def removeValue(goner:Int) = {
      val newList = possibleValues.filter(_!=goner);
      new Square(this.boxNumber,this.xNumber,this.yNumber,newList,false);
    }
  }
  var s1 = new Square(1,1,1);
  s1 = s1.setValue(1);
  println(s1.possibleValues);
  
  
  var s2 = new Square(1,1,1);
  //s2 = s2.setValue(1);
  s2 = s2.removeValue(4);
  println(s2.possibleValues);
  
  var allSquares = List[Square]();
  
  def getBoxFromXY(x:Int,y:Int):Int = {
    if(x<=2 && y<=2)
      return 1;
    
    else if(x>2 && y<=2)
      return 2;
    
    else if(x<=2 && y>2)
      return 3;
    
    else 4;
  }
  
  def getBoxFromXY2(x:Int,y:Int):Int = {
    (x,y) match
    {
      case (1|2,1|2) => 1
      case (3|4,1|2) => 2
      case (1|2,3|4) => 3
      case (x,y) => 4
    }
  }
  
  for(xvalue <- List(1,2,3,4))
  {
    for(yvalue <- List(1,2,3,4))
    {
      val s = new Square(getBoxFromXY(xvalue,yvalue),xvalue,yvalue);
      allSquares = allSquares :+ s;
    }
  }
  
  def getAllFromX(i:Int):List[Square] = {
    return allSquares.filter((s:Square)=>s.x==i);
  }
  
  getAllFromX(1).foreach(s => println(s.x +" "+s.y));
  
  
  //Lists
  
  val oneList = List(1,2,3,4,"Hi",false);
  val anotherList = List[Any](1,2,3,4,5,"Hi",false);
  
  for(i<-oneList)
  {
    println(i);
  }
  
  def n(x:Any) = {println(x)}
  
  oneList.foreach(n);
  
  oneList.foreach((x:Any) => println(x));
  
  oneList.foreach(println(_));
  
  
  val l = List(1,2,3,4,5);
  def div(x:Int) = x/2;
  l.foreach(x=>println(div(x)));
  
  val winningList = List(1,2,3,6);
  val num = List(1,2,3,9);
  println(num.forall{(x:Int)=>winningList.contains(x);});
  
  println(allSquares.forall((x:Square)=>x.possibleValues.contains(1)));
  allSquares = allSquares :+ allSquares(0).setValue(2);
  println(allSquares.forall((x:Square)=>x.possibleValues.contains(1)));
  
  allSquares = allSquares.updated(0,allSquares(0).setValue(1));
  var sq = getAllFromX(1);
  println(sq.exists{(s:Square) => s.possibleValues == List(1)});
  
  def squareFunc(x:Int) = x*x;
  val l2 = l.map(x=>squareFunc(x));
  println(l2);
  
  
  //Tuple, lister som ikke kan endres (immutable).
  val a = (99,"red ballons");
  println(a._1 + " " + a._2 + " floating in the sky.");
  
  def incTwo(x:Int,y:Int):Tuple2[Int,Int] = {return (x+1,x+2);}
  
  val(one,two) = incTwo(2,8);
  println(one +" " + two);
  
  
  def twoInt(x:Int):Tuple2[Int,Int] = {return (x-1,x+1);}
  val(xx) = twoInt(1);
  println(xx);
  
  */
  
  //Assignment
  
  class Square(boxNumber:Int,xNumber:Int,yNumber:Int,values:List[Int]=List(1,2,3,4),solved:Boolean=false)
  {
    val possibleValues = values;
    val x = xNumber;
    val y = yNumber;
    
    def setValue(solution:Int) = {
      new Square(this.boxNumber,this.xNumber,this.yNumber,List(solution),true);
    }
    
    def removeValue(goner:Int) = {
      val newList = possibleValues.filter(_!=goner);
      new Square(this.boxNumber,this.xNumber,this.yNumber,newList,false);
    }
  }
  var s1 = new Square(1,1,1);
  s1 = s1.setValue(1);
  //println(s1.possibleValues);
  
  
  var s2 = new Square(1,1,1);
  //s2 = s2.setValue(1);
  s2 = s2.removeValue(4);
  //println(s2.possibleValues);
  
  var allSquares = List[Square]();
  
  def getBoxFromXY(x:Int,y:Int):Int = {
    if(x<=2 && y<=2)
      return 1;
    
    else if(x>2 && y<=2)
      return 2;
    
    else if(x<=2 && y>2)
      return 3;
    
    else 4;
  }
  
  for(xvalue <- List(1,2,3,4))
  {
    for(yvalue <- List(1,2,3,4))
    {
      val s = new Square(getBoxFromXY(xvalue,yvalue),xvalue,yvalue);
      allSquares = allSquares :+ s;
    }
  }
  
  def getAllFromX(i:Int):List[Square] = {return allSquares.filter((s:Square)=>s.x==i);}
  
  getAllFromX(2).foreach(s => println(s.x +" "+s.y));
  
  def getAllFromBox(X:Int,Y:Int):List[Square] = {return allSquares.filter((s:Square)=>s.x==X);}
  
  getAllFromBox(2,1).foreach(s => println(s.x +" "+s.y));
  
  //END
}