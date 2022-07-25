public class Solution 
{
	public static String reverseString(String s) 
	{
		s=s.trim();
        String[] words=s.split(" ");
        
        String ans="";
        String word="";
        for(int i=words.length-1;i>=0;i--){
            word=words[i];
            word=word.trim();
            if(word.equals(" ")||word.isEmpty())
                continue;
            else{
                //System.out.println(word);
                ans+=word+" ";
            }
            
        }
        
        ans=ans.trim();
        return ans;
	}
}
