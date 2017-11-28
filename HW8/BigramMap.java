//import javafx.util.Pair;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;

@SuppressWarnings("unchecked")
public class BigramMap<T> implements Bigram<T>
{
	private int dataType;
	private int size;
	private Map< Pair<T,T>, Integer > myMap=null;
	private Pair<T,T>[] pair=null;
	private List<Object> myData=null;
	private int sizeMap;

	public BigramMap()
	{
	}
	public BigramMap(int type)
	{
		dataType = type;
		myMap=new HashMap<>();
		myData=new ArrayList<>();
	}
	public final int getType()
	{
		return dataType;
	}
	public void setSize(int sizeData)
	{
		size=sizeData;
			
	}
	public int getSize()
	{
		return size;
	}
	@Override
	public void readFile(String fileName) throws Exception
	{
		try
		{
			File file = new File(fileName);
	    	Scanner scanner=new Scanner(file);
	    	
	    	int count=0;
	    	while(scanner.hasNext())
	    	{
	    		++count;
	    		scanner.next();
	    	}// dosyada kac tane eleman oldugunu hesaplama	
	    	try
	    	{
	        	scanner=new Scanner(file);
	        	if(dataType==1)
	        	{
	        		while(scanner.hasNextInt())
	            	{
	            		myData.add(scanner.next());
	            	}
	        	}// integer icin ekleme	
	        	else if(dataType==2)
	        	{
	        		while(scanner.hasNext())
	        		{	
	            		myData.add(scanner.next());
	        		}
	        	}// string icin ekleme
	        	else if(dataType==3)
	        	{
	        		while(scanner.hasNext())
	            	{
	            		myData.add(scanner.next());
	            	}
	        	}// double icin ekleme(hasNextDouble() neden calismadi anlamadim)
	        	// bad data kontrolu
	        	if(myData.size()!=count)
	            	throw new MyException("BAD DATA!!");
	        }
	        catch(FileNotFoundException e)
	        {
	        	e.printStackTrace();
	        }
			setSize(myData.size());

			if(size==0)
			{
				throw new MyException("EMPTY FILE");
			}
			pair=new Pair[size-1];// pair array icin yer al
			for(int i=0; i<size-1; ++i)
			{
				pair[i]=new Pair(myData.get(i),myData.get(i+1));
			}// tum verileri pair yaptim
			
			int m;
			for(int i=0; i<getSize()-1; ++i)
			{	
				boolean flag=true;
				for(m=0; m<i && flag!=false; ++m)
				{
					if(myData.get(i).equals(pair[m].first) && myData.get(i+1).equals(pair[m].second))
					{
						flag=false;
					}
				}// gelen pairin mapte olup olmadıgını kontrol ettim
				if(flag==false)
				{	
					int j=myMap.get(pair[m-1]);
					myMap.put(pair[m-1], j+1);
				}// eger mapte varsa sadece value degerini arttirdim
				else if(flag==true)
				{	
	            	myMap.put(pair[i], 1);
	         	}// mapte yoksa ekledim
			}	
		}
		catch(MyException e)
		{
			System.out.println(e);
		}
	}	
	@Override
	public int numGrams()
	{
		return size-1;
	}
	@Override
	public int numOfGrams(T v1, T v2)
	{
		//System.out.println(v1+" "+v2);
		int count=0;
		Pair p=new Pair(v1,v2);
		for(int i=0; i<sizeMap; ++i)
		{	
			//System.out.println(pair[i].getFirst());
			if(pair[i].getFirst()==(v1) && pair[i].getSecond()==(v2))
			{	
				return (myMap.get(p));
			}
		}
		return count;	
	}// neden calismiyor anlamiyorum
	public String toString(){

		int max=0;
		int count;

		for(Pair<T,T> key : myMap.keySet()){

			if(myMap.get(key)>max)
			{
				max=myMap.get(key);
			}
		}// max value bul
		for(Pair<T,T> key : myMap.keySet()){
			
			for(Pair<T,T> key1 : myMap.keySet()){

				if(myMap.get(key1)==max)
				{
					System.out.println("BigramMap(" +  key1.first + "," +	key1.second + ") :  " + myMap.get(key1));
				}
			}
			--max;
		}// buyukten kucuge dogru print et
		return "";
	}
}