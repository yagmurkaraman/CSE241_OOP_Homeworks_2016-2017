import java.io.FileNotFoundException;
import java.util.IllegalFormatException;
import java.io.*;

@SuppressWarnings("unchecked")
public interface Bigram <T>{

    public void readFile (String fileName) throws Exception;
    public int numGrams();
	public int numOfGrams(T v1, T v2);
	public String toString();
}