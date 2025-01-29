<h1 align="center">c-eshop-pipes</h1>
This repository contains the code for a project assigned as part of a prgramming lab, as a way to evaluate and enhance our knowledge in inter-process communication (IPC) utilising pipelines, and the fork() function.
<br></br>

> [!NOTE]
> You may find a version of this project that utilises sockets instead of pipelines [here](https://github.com/taxpater/C-eshop-sockets).

Moreover, it is a simulation of an e-shop selling laptops, where a CLIENT_AMOUNT of different clients submit ORDER_AMOUNT of orders each to the server, waits for the server to process each one their orders as they are being submitted one by one, and then replies to them with whether the order was completed successfully or not, with CLIENT_AMOUNT & ORDER_AMOUNT being set in the func.c file. The product catalog is created automatically on each iteration through the InitialiseCatalog function, with each product having a set amount of stock, and the calalog having a set size defined by the PRODUCT_CNT & CATALOG_SIZE variables correspondigly. When all orders are processed, the server outputs a statistics report of the performance of each product, and of the shop as a whole.
<br></br>
The code contains comments in most parts to ensure easy understanding of it's functionality.
<br></br>

> [!WARNING]
> If you wish to run this program on your local system as is, it is required to be using a UNIX system that supports make-file, and has the gcc compiler available. In any other case, you will have to modify the make-file to use the compiler of your choice, or compile all the files one by one manually.

<h2 align="center">Contributions</h1>
As this repository serves as an archive for the project, contributions will not be accepted on the main branch, unless they are adressing a possible error with my code, or suggesting minor improvements that don't alter what the code does.
