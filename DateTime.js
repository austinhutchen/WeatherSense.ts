import React, {useEffect,useState} from 'react'
import {View,Text, Stylesheet} from 'react-native'
import { styles } from './styles'

const WeatherItem= ({title,value,unit})=>{

return(
 <View style={styles.WeatherItem}>
<Text style={styles.WeatherItemTitle}>{title}</Text>
<Text style={styles.WeatherItemTitle}>{value}{unit}</Text> 

 </View>



)

}

const DateTime=async() =>{
const [date,SetDate]=useState('');
const [time,setTime]= useState('');
  let url = "";
  await axios.get(url).then(response)=>{
let _data=  response.toJSON();
}
this.setDate(_data.toJSON());



}
