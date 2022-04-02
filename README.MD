<h1 align="center">
    <img src="./images/inside.jpg" alt="inside" width="400">
</h1>

# ARDUINO BASED TURBIDITY SENSOR

<p align="center">
    <a href="#Project Description">Project Description</a> •
    <a href="#How to build it">How to build it</a> •
    <a href="#Photos">Photos</a> •
    <a href="#Video">Video</a> •
    <a href="#About the code">About the code</a> •
    <a href="#Simplicity">Simplicity</a> •
    <a href="#Special Thanks">Special Thanks</a>
</p>

<br>

## Project Description
> As a real turbidity sensor (which is sold in electronics stores) usually has a high price, the idea of this project came to replace such equipment with lower-priced ones and obtain a similar result. Consisting basically of an Arduino UNO and an LDR resistor, the project also becomes more customizable depending on the purpose for which it is intended.
>
> Through an external light source that passes through the glass of water, it is possible to capture the voltage of the LDR resistor and transform this data into a certain level of turbidity of the liquid. The higher the voltage, the dirtier the water is.

<br>

## How to build it
> Materials
<ul>
    <li>1 Box</li>
    <li>Cup holder</li>
    <li>Flashlight</li>
    <li>Arduino UNO</li>
    <li>Protoboard</li>
    <li>1 LDR resistor</li>
    <li>5 led's</li>
    <li>6 330Ω (Ohms) resistors</li>
    <li>Jumpers</li>
</ul>

> Mounting
<ul>
    <li>First you have to make the cuts in the box to fit the elements and then place them in the right position, with the LDR just below the cup. It is advisable to paint the box black to help retain more the light. Afterwards, the necessary connections of the components are made on the protoboad, always remembering to position the LEDs in order to facilitate their visualization. Finally, the Arduino is connected to the computer to pass the code and put the system into running. To use, just place your water sample in the appropriate place and see the result based on the color of the LEDs.</li>
</ul>

<h1 align="center">
    <img src="./images/operation.gif" alt="operation gif">
</h1>

![](./images/schematic.png)

<br>

## Photos

![](./images/front.jpg)
![](./images/inside.jpg)


<br>

## Video

> The full presentation can be found here -> https://youtu.be/-e1VBkAoZOs

<br>

## About the code

> At the beggining, we manually calibrated the software to get the right values of voltagem as each level of turbidity. But that proved to be really not practical and so we decided that the program has a loop at the beggining, that automatically calibrates itself for the next readings of samples. 

The mantioned part of the code can be seen in here

```c
int calibra(){
  double lido = analogRead(LDR);
  double anterior=0;
  double diferenca=0;


  int vezes=0;

  while(vezes<1000){
    lido = analogRead(LDR);
    diferenca = anterior-lido;
    
    if (diferenca < 100) {
      vezes++;
    } else vezes=0;

    anterior = lido;
  }
  
  parametros[0] = lido;
  parametros[1] = lido+10;
  parametros[2] = lido+20;
  parametros[3] = lido+30;
 }
```
> The rest of the code is pretty simple, and can be directly seen on the git files in this repository.

<br>

## Simplicity
> As you can see, despite having a set of relatively simple materials (with components easily found in computer stores and other home materials), the system has a very useful and interesting application that can be extended to some research or extension project, such as a future improvement and implementation in needy communities that, with the help of this equipment, could analyze the quality of the water that arrives in the place where they live and who knows, make an appeal to the authorities, directly improving their quality of life.

<br>

## Special Thanks
> The owners of this code sincerely thanks the help from the UFES's Teacher and Lab Manager **_Vinicius Motta_** during this project development.

<br>

----

Made with 🤍 by
* CAIO FIOROTTI 👏 [See my GitHub](https://github.com/fiorotticaio) 
* HENRIQUE CAETANO 👏 [See my GitHub](https://github.com/1700KeeQ) 
* MATHEUS SCHREIBER 👏 [See my GitHub](https://github.com/matheusschreiber)

<br>
                

