import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;

@SuppressWarnings("unchecked")
public class BigramDyn<T> implements Bigram<T>
{
	private T[] myData = null;
    private Pair<Pair<T,T>, Integer> [] myDyn = null;
    private int dataType;
    private int used;
    private int sizeDyn;
    private int size;


	public BigramDyn()
	{
		used=0;	
	}
	public BigramDyn(int type)
	{
		dataType=type;
	}
	public void setSize(int sizemyData)
	{
		size=sizemyData;
			
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
	    	Scanner scanner;
	    	scanner = new Scanner(file);
			int index=0;

			
	    	int count=0;
			while (scanner.hasNext()) {

				String line=scanner.next();
				++count;
			}// dosyadaki eleman sayisini bul
			setSize(count);
			if(count==0)
			{
				throw new MyException("EMPTY FILE");
			}// dosya bos mu kontrolu
			scanner=new Scanner(file);
			myData=(T[])new Object[count];

			if(dataType==1)
        	{
            
        		while(scanner.hasNextInt())
            	{
					String line=scanner.next();
					myData[index]=(T)line;
					++index;            	
            	}
        	}	
        	else if(dataType==2)
        	{
        		while(scanner.hasNext())
            	{
					String line=scanner.next();
					myData[index]=(T)line;
					++index;            	
            	}
        	}
        	else if(dataType==3)
        	{
        		while(scanner.hasNext())
            	{
					String line=scanner.next();
					myData[index]=(T)line;
					++index;            	
            	}
        	}
        	if(index!=count)
            	throw new MyException("BAD DATA!!");

			myDyn=new Pair[getSize()];
			int k=0;
			for(int i=0; i<getSize()-1; ++i)
			{
				boolean flag=true;
				Pair<T,T> myPair=new Pair<>(myData[i], myData[i+1]);
				for(int j=0; j<k; ++j)
				{
					if((myDyn[j].first.first).equals(myPair.first) && (myDyn[j].first.second).equals(myPair.second))
					{
						
						myDyn[j].second++;
						flag=false;
					}	
				}
				if(flag==true)
				{
					myDyn[k]=new Pair<>(myPair,1);
					++k;

				}
			}
			sizeDyn=k;
		}
		catch(FileNotFoundException e)
        {
        	e.printStackTrace();
        }
		catch(MyException e)
		{
			System.out.println(e);
		}			
	}
	@Override
	public int numGrams(){
		return getSize()-1;
	}
	@Override
	public int numOfGrams(T v1, T v2){

		int found=0;
		for(int i=0; i<getSize()-1; ++i)
		{
			if(myData[i]==v1 && myData[i+1]==v2)
			{	
				found++;
			}
		}
		return found;
	}
	public String toString(){

		int max=myDyn[0].second;
		int i,j=0;
			
		for(i=0; i<sizeDyn; ++i)
		{
			if(myDyn[i].second>max)
			{	
				max=myDyn[i].second;
				++j;
			}			
		}
		// j -- maxGrams
		for(int k=0; k<sizeDyn; ++k)
		{	
			for(int m=0; m<sizeDyn; ++m)
			{
				if(myDyn[m].second==max)
				{
					System.out.println("BigramDyn(" +  myDyn[m].first.first + "," + myDyn[m].first.second + ") :  "+
					myDyn[m].second);
				}

			}	
		max--;
		}

		return "";
	}

}