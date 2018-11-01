package com.example.atik.fall_detector;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

public class starting extends AppCompatActivity {
    Button stBtn,settingBtn;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_starting);

        stBtn=(Button)findViewById(R.id.start_btn);
        settingBtn=(Button)findViewById(R.id.stn_btn);

        stBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent i=new Intent(starting.this,DeviceListActivity.class);
                startActivity(i);
            }
        });

        settingBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent j=new Intent(starting.this,setting.class);
                startActivity(j);
            }
        });
    }

}
