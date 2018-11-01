package com.example.atik.fall_detector;

import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

public class setting extends AppCompatActivity {
    Button save_btn;
    EditText edt1,edt2;
    public static final String MyPREFERENCES = "MyPrefs" ;
    public static final String phn = "phoneKey";



    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_setting);

        save_btn=(Button)findViewById(R.id.save_btn);
        edt1=(EditText)findViewById(R.id.editText1);
        edt2=(EditText)findViewById(R.id.editText2);




        save_btn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                savedInfo();
                Toast.makeText(setting.this,"Saved",Toast.LENGTH_LONG).show();
                Intent i=new Intent(setting.this,DeviceListActivity.class);
                startActivity(i);
            }
        });
    }

    public void savedInfo(){
         SharedPreferences sare=getSharedPreferences("userInfo",Context.MODE_PRIVATE);
        SharedPreferences.Editor editor=sare.edit();

        editor.putString("username",edt1.getText().toString());
        editor.putString("message",edt2.getText().toString());
        editor.apply();
    }
}
