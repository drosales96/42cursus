# NetPractice

Básicamente vamos a realizar un proyecto el cual se compone de 10 ejercicios que tienen que ver con Redes, específicamente tareas que puede tener que realizar un sysadmin (Administrador de Sistemas). A continuación voy a dejar aquí reflejada información de utilidad para tener una idea sobre redes.

## IP

Una IP (Internet Protocol) básicamente es un número de dirección de un activo, por ejemplo podríamos decir que nuestra IP es la dirección de nuestra casa donde queremos que Amazon nos traiga los paquetes. Por lo tanto para poder recibir y enviar información (paquetes de datos), necesitamos poder verificar siempre cual es el remitente y cual el destinatario.

## IPv4

Esté tipo de dirección de IP se creó en 1981, y es un número que se compone de 32 bits compuesto por 4 octetos y separados por puntos (por ejemplo 192.138.1.8), se pueden generar unas 4.3 millones de IP con este formato, pero a medida que pasaba el tiempo, se quedaba corta esa cantidad por lo que después nació el siguiente tipo de IP, que sería IPv6.

## IPv6

Este tipo de IP se creó en 1998, y es un número compuesto por 128 bits, representado por números hexadecimales, separador por dos puntos ":". Este tipo de IP puede brindar un número casi infinito de direcciones (un ejemplo sería -> 2001:0db8:85a3:0000:0000:8a2e:0370:7334).

Tras saber algo sobre las IP tambien necesitamos saber que hay dos tipos de IP y estas pueden ser:

    - IP Pública: Es proporcionada por in ISP (proveedor de servicio de internet), usada para comunicarte a través de la red general de internet.

    - IP Privada: Es una IP que tienes en tu área local (LAN) y es la que se usa para identificar aquellos activos dentro de tu zona, como pueden ser móviles, impresoras, etc..

    Dentro de la IP Privada hay tres tipos de ellas:

    - Clase A: es una IP que ofrece 8 bits para la red y 24 bits para el Host y es usadad comunmente en instituciones grandes como Universidades o Complejos de estado, etc.. Su máscara de subred sería (255.0.0.0), y tiene una capacidad de 16 millones de IP.

    - Clase B: es una IP que ofrece 12 bits para la red y 20 para el Host, y es usada para oficinas medianas, o centros intermedios en cuanto a tamaño. Su máscara de subred sería 255.240.0.0, tiene una capacidad de 1 millón de IP.

    - Clase C: es una IP que ofrece 24 bits para la red y 8 bits para el Host, su máscara de subred predeterminada sería 255.255.255.0, tiene una capacidad de IP de aproximadamente algo más de 65k y es la más común para el uso doméstico.

A continuación, según su asignación, una IP puede ser de dos diferentes tipos:

    - IP estática: es una IP que no cambia, se mantiene fija, es ideal para equipos o servidores que necsiten una IP fija, aunque es más costosa y necesitas gestionarla de manera manual.

    - IP dinámica: es un tipo de IP que varía cada vez que te conectas a internet y es brindada por un servidor DHCP, que se encarga de gestionarlas, además es la más común entre los usuarios a nivel doméstico, ya que es más barata de mantener.

Después necesitamos saber que hay diferentes tipos de IP según el alcance que tengan, estos tipos son:

    - IP Unicast: es una IP que identifica a un solo dispositivo (lo más común en la sociedad), y se usará para comunicar un activo con otro.

    - IP Broadcast: es una IP que tiene un alcance bastante mayor, comunicándose con todos los dispositivos dentro de una red local, un ejemplo podría ser (192.138.1.0/24).

    - IP Multicast: es una IP que permite mandar una serie de datos a un grupo específico dentro de una red, por ejemplo este tipo de IP es usada en streaming de video, etc...

## TCP

TCP es un protocolo que se encarga de llevar los paquetes de datos de manera segura desde el emisor hasta el receptor. Su siglas se refieren a Transmission Control Protocol. Digamos que en el proceso de envío de paquetes de datos que ocurre entre un emisor y un receptor se hace una conexión parecida a un tunel entre 3 vías (EMISOR | RECEPTOR | TCP+IP), la IP que es un protocolo no muy seguro ya que se aplica sin conexión y no hace ningún tipo de aseguración sobre el emisor y el receptor, así que entra en juego TCP que junto a la IP hacen seguro el camino.

Por ejemplo imaginemos que realizamos una solicitud HTTP a un servidor, pues TCP se encargará que todo llegue de manera segura al servidor, mientras observa como la IP lleva los paquetes. Una vez todo está en el servidor y este ofrece una respuesta, ambos (TCP/IP) traen de vuelta la respuesta de manera segura.

¿Porqué TCP/IP es seguro y se encarga de verificar el recorrido?:

    - Recibe los datos o archivos a enviar para tenerlos el solamente.
    - TCP divide los datos en segmentos, añade información de control (como números de secuencia) y pasa estos segmentos al protocolo IP, después IP encapsula los segmentos en paquetes IP, añadiendo direcciones IP de origen y destino.
    - Estos paquetes IP viajarán por múltiples routers y redes hasta poder llegar al destino.
    - Una vez estamos en el destino, IP extrae los segmentos de los paquetes que ha encapsulado y se los pasa a TCP.
    - TCP se va encargar de ordenar todas esas fracciones de los paquetes (ya que pueden llegar desordenados al viajar por la red), verifica que no falten datos, ya que si faltan por llegar los reclama, incluso verifica que no hayan datos corruptos.
    - Una vez todo está ensamblado y no faltan datos, se entregan al servidor, que puede ser de una app o navegador, que luego brindará su respuesta y nos llegará de vuelta.

## Switch

Un Switch es un dispositvo que sirve para el control de tráfico de red dentro de una red local donde tenemos varios activos, como podría ser una oficina donde podemos tener PCs, laptops, impresoras, tablets, etc..

Estos dispositivos realmente trabajan con direcciones MAC (Media Access Control), lo hacen de manera que una vez conectamos los activos a los puertos del Switch éste los enlaza con una MAC a cada uno, para después en el proceso de tráfico de red, comunique aquellos dispositivos que corresponde, evitando así que haya una sobrecarga de información en la red. Puntos positivos de los Switch es que dividen la red en fragmentos para facilitar el transporte de la información, además de que trabajan en la capa 2 del modelo OSI, usando las MAC para la tranferencia de datos, también permiten transferencias en ambos sentidos lo que le hace más eficiente, y además tiene bajo retardo.

Existen 3 tipos de Switch y estos son:

    - Switch no gestionado: es un dispositivo de plug and play, que se usa sobre todo a nivel doméstico, ya que no necesita configuración, y no ofrece herramientas avanzadas para segmentar los datos, o monitorear la red.

    - Switch gestionado: permite configuraciones avanzas por ejemplo para crear VLANs (Virtual Local Adress Network), monitorear y segmentar los datos de la red y la priorización de datos (QoS). Se suelen usar en empresas donde hay bastantes activos.

    - Switch de capa 3: trabaja en la capa 2 y la capa 3 del modelo OSI, y permiten funciones de enrutamiento y conmutación. Normalmente se usan en redes muy grandes donde hay muchos activos.