public class MyException extends Exception
{
		public MyException(String message)
		{
			printMessage = message;
			//System.out.println(printMessage);
			getMessage();
		}
		public String getMessage()
		{
			return printMessage;
		}
		
		private String printMessage;
}
