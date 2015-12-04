public class Time{
	public String whatTime(int seconds){
		int sec = seconds % 60;
		seconds = seconds / 60;

		int min = seconds % 60;
		int hour = seconds / 60;
		
		return "" + hour + ":" + min + ":" + sec;
	} 	
}
