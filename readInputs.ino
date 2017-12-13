void doSwitch(){
  oldLupSts=LupSts;
  LupSts=digitalRead(Lup);
  oldLdnSts=LdnSts;
  LdnSts=digitalRead(Ldn);
  if((not(LupSts == oldLupSts))||(not(LdnSts == oldLdnSts))) {
    if(LupSts==1){ 
      dir=1; 
      digitalWrite(Htr,1);
    } else { 
      dir=-1; 
      digitalWrite(Htr,0);
    }
    if(LdnSts==1){ 
      digitalWrite(Pmp,1);
    } else { 
      digitalWrite(Pmp,0);
    }
    Serial.print("Switch Status: ");
    Serial.print(LupSts);
    Serial.println(LdnSts);
  }
}
//---------------------------------------------------------------------------------------------------------------

