import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.ObjectInputStream;




public class Runner {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		/*try {
			FileReader f = new FileReader("eksamensoppgaver.txt");
			int i = f.read();
			while(i>-1){
				System.out.print((char)i);
				i = f.read();
			}
			f.close();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}*/
		
		/*try {
			FileReader f = new FileReader("eksamensoppgaver.txt");
			BufferedReader bf = new BufferedReader(f);
			String linje = bf.readLine();
			while(linje!=null){
				JOptionPane.showMessageDialog(null,linje);
				linje = bf.readLine();
			}
			bf.close();
			f.close();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}*/
		
		/*try {
			URL u = new URL("http://mortengoodwin.net/dat101/hobbit");
			InputStreamReader i = new InputStreamReader(u.openStream());
			BufferedReader br = new BufferedReader(i);
			String linje = br.readLine();
			while(linje!=null){
				System.out.println(linje);
				linje = br.readLine();
			}
			br.close();
			i.close();
		} catch (MalformedURLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}*/
		
		//new MittVindu();
		/*try {
			FileWriter f = new FileWriter("alver.txt");
			f.write("Galadriel\n");
			f.write("Gil-galad\n");
			f.write("Feanor\n");
			f.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}*/
		
		/*try {
			FileWriter f = new FileWriter("listeovernavn.txt");
			BufferedWriter bf = new BufferedWriter(f);
			String[] forste = {"Mo","Jo","Ma","El"};
			String[] andre = {"rt","na","thi"};
			Random rg = new Random();
			for (int i = 0; i < 1000000; i++) {
				String navn = forste[rg.nextInt(forste.length)]+
						andre[rg.nextInt(andre.length)];
				bf.write(navn);
				bf.write("\n");
			}
			bf.close();
			f.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}*/
		
		/*Ansatt t1 = new Ansatt();
		t1.setNavn("Morten");
		t1.setTimer(100);
		try {
			FileOutputStream fos = new FileOutputStream("enreg");
			ObjectOutputStream o = new ObjectOutputStream(fos);
			o.writeObject(t1);
			o.close();
			fos.close();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}*/
		/*try {
			FileInputStream fin = new FileInputStream("enreg");
			ObjectInputStream oin = new ObjectInputStream(fin);
			Ansatt t2 = (Ansatt) oin.readObject();
			System.out.println(t2.getNavn() + " " + t2.getTimer());
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (ClassNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}*/
		
		new MittVindu();
		
	}

}