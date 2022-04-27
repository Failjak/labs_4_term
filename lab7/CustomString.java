public class CustomString {

    public static String concat(String[] strs){
        
        String res_str = "";
        for (int i = 0; i < strs.length; i++){
            res_str += strs[i];
        }

        return res_str;
    }

    public static String concat_ws(String[] strs, String ws){

        String res_str = "";
        int i = 0;

        for (i = 0; i < strs.length - 1; i++){
            res_str += strs[i] + ws;
        }

        return res_str + strs[i];
    }

    public static int length(String str){
        return str.length();
    }

    public static String ltrim(String str){
        return "FD";
    }

}