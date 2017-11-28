public class Pair<T1, T2>
{
	public T1 first;
	public T2 second;

	public Pair()
	{
		first=null;
		second=null;
	}
	public Pair(T1 firstValue, T2 secondValue)
	{
		first=firstValue;
		second=secondValue;
	}
	public void setFirst(T1 firstValue)
	{
		first=firstValue;
	}
	public T1 getFirst()
	{
		return first;
	}
	public void setSecond(T2 secondValue)
	{
		second=secondValue;
	}
	public T2 getSecond()
	{
		return second;
	}
}