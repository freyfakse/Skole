

object Day_3 extends App {
  
  /*
  
  var jetSet = Set("Boeing","Airbus","Boeing"); //Set inneholder kun én av hver unike element
  
  for(i <- jetSet)
  {
    println(i)
  }
  
  val l = List(1,2,2,2,2,2,3,3,3,3,3,4,4,4,7);
  
  val s = l.toSet[Int];
  for(i<-s)
  {
    println(i + ":" + l.count(_ == i));
  }
  
  println("_______________________________________________________")//Spacer
  
  val l2 = List("e","e","e","t","t","i","i","i","i","i","h","h","h");
  val s2 = l2.toSet;
  for(i<-s2)
  {
    println(i+": "+l2.count(_==i));
  }
  
  println("_______________________________________________________")//Spacer
  
  val romans = Map[Int,String](1->"I",2->"II",3->"III");
  println(romans(2));
  
  for((arabic,roman)<-romans)
  {
    println(arabic +":"+roman);
  }
  
  val cc = Map[String,String]("Norway"->"Oslo","UK"->"London","France"->"Paris");
  
  for((country,capital)<-cc)
  {
    println(country+":"+capital);
  }
  
  
  
  //Singleton
  class Conf
  {
    var username = "Morten";
    var password = "Secret";
  }
  
  val c = new Conf();
  println(c.username);
  
  object Configuration //Objekt uten klasse
  {
    var username = "Morten";
    var password = "Secret"
  }
  
  println(Configuration.username);
  
  println("_______________________________________________________")//Spacer
  
  object Logger
  {
    def time(str:String):Unit = {println(java.util.Calendar.getInstance().getTime() +" " +str)}
  }
  
  Logger.time("Something");
  
  println("_______________________________________________________")//Spacer
  
  //Implicit corrections
  
  implicit def doubleToInt(x:Double):Int = {
    x.toInt;
  }
  
  val i:Int = 3.5;
  println(i);
  
  println("_______________________________________________________")//Spacer
  
  implicit def stringToSize(str:String):Int = {
    return str.length();
  }
  
  val i2:Int="hei";
  println(i2);
  
  class Square(xNumber:Int,yNumber:Int,boxNumber:Int,values:List[Int]=List(1,2,3,4),solved:Boolean=false)
  {
    var possibleValues = values;
    val x = xNumber;
    val y = yNumber;
    val box = boxNumber;
    var s = solved;
    
    def setValue(solution:Int) = {
      
      this.s = true;
      
      this.possibleValues = List(solution);
      
    }
    
    def removeValue(wrongSolution:Int) = {
      if(this.s==false)
      {
        this.possibleValues = this.possibleValues.filter(_ != wrongSolution);
        if(this.possibleValues.length==1)
        {
          this.setValue(this.possibleValues(0));
        }
      }
    }
  }
  
  implicit def intToSquare(i:Int):Square = {
    new Square(1,1,1,List(i));
  }
  
  val s:Square = 4;
  println(s.possibleValues);
  
  println("_______________________________________________________")//Spacer
  
  def getBoxFromXY(x:Int,y:Int):Int = {
    (x,y) match
    {
      case (1|2,1|2) => 1
      case (3|4,1|2) => 2
      case (1|2,3|4) => 3
      case (x,y) => 4
    }
  }
  
  var allSquares = List[Square]();
  
  for(x<-List(1,2,3,4))
  {
    for(y<-List(1,2,3,4))
    {
      val s = new Square(x,y,getBoxFromXY(x,y));
      allSquares = allSquares :+s;
    }
  }
  
  def getAllFromX(i:Int):List[Square] = {
    return allSquares.filter((s:Square)=>s.x==i);
  }
  
  def getAllFromy(i:Int):List[Square] = {
    return allSquares.filter((s:Square)=>s.y==i);
  }
  
  def getAllFromBox(i:Int):List[Square] = {
    return allSquares.filter((s:Square)=>s.box==i);
  }
  def getSquare(i:Int):List[Square] = {
    return allSquares.filter(_.x==x).filter(_.y==y)(0);
  }
  
  def setValue(x:Int,y:Int,solution:Int) = {
    var s = getSquare(x,y);
    allSquares = allSquares.filter(_ != s);
    s.setValue(solution);
    allSquares = allSquares :+ s;
  }
  
  def removeValue(x:Int,y:Int,wrongSolution:Int) = {
    var s = getSquare(x,y);
    allSquares = allSquares.filter(_ != s);
    s.setValue(wrongSolution);
    allSquares = allSquares :+ s;
  }
  
  setValue(1,1,3);
  setValue(1,2,4);
  setValue(1,3,1);
  setValue(2,2,2);
  setValue(3,3,2);
  setValue(4,2,1);
  setValue(4,3,4);
  setValue(4,4,3);
  
  def printit
  
  //Partially applied functions
  
  def multiply(a:Double,b:Double,c:Double):Double = {
    return a*b*c;
  }
  
  def multiply2 = multiply(_:Double,_:Double,2)
  
  
  println(multiply2(2,3))
  println(multiply(2,3,2))
  
  
  
  //Assignments
  
  def filteredList(l:List[Any]):List[Any] = {
    for(i <- l)
    {
      l.filter(p)
    }
    var k = List();
    
    return k;
  }
  
  var jet = List(1,2,2,3,3,3);
  
  println(filteredList(jet));
  
  */
  
  //END
}