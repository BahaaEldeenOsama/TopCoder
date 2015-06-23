public class BinaryCode{
	public String[] decode(String message){
		String[] decoded = new String[2];
		decoded[0] = decodeUtill(message, '0');
		decoded[1] = decodeUtill(message, '1');
		return decoded;
	}
	public String decodeUtill(String message, char num){
		if(message.length() == 1){
			if(message.charAt(0) == num)
				return message;
			else
				return "NONE";
		}
		boolean flag = true;
		char[] code = new char[message.length()];
		code[0] = num;
		char temp = (char)  (message.charAt(0) - num + '0');
		if( temp < '0')
			flag = false;
		code[1] = temp;
		int upperBound = message.length() - 1;
		
		for(int i = 1; i < upperBound && flag ; ++i){
			temp = (char) (message.charAt(i) - code[i] + '0' - code[i-1] + '0');
			if( temp < '0' || temp > '3')
				flag = false;
			code[i+1] = (char) temp;
		}
		
		if(!flag ||  message.charAt(upperBound) != code[upperBound] - '0' + code[upperBound-1])
			return "NONE";
		return new String(code);
	}
}
