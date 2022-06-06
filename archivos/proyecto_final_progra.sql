-- MySQL dump 10.13  Distrib 8.0.28, for Win64 (x86_64)
--
-- Host: localhost    Database: proyecto final super mercado
-- ------------------------------------------------------
-- Server version	8.0.28

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `clientes`
--

DROP TABLE IF EXISTS `clientes`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `clientes` (
  `idCliente` int NOT NULL AUTO_INCREMENT,
  `nombres` varchar(60) DEFAULT NULL,
  `apellidos` varchar(60) DEFAULT NULL,
  `NIT` varchar(12) DEFAULT NULL,
  `genero` bit(1) DEFAULT NULL,
  `telefono` varchar(25) DEFAULT NULL,
  `correo_electronico` varchar(45) DEFAULT NULL,
  `fechaingreso` datetime DEFAULT NULL,
  PRIMARY KEY (`idCliente`)
) ENGINE=InnoDB AUTO_INCREMENT=8 DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `clientes`
--

LOCK TABLES `clientes` WRITE;
/*!40000 ALTER TABLE `clientes` DISABLE KEYS */;
INSERT INTO `clientes` VALUES (1,'CONSUMIDOR','FINAL','C/F',_binary '','0','0','2014-07-12 00:00:00'),(2,'JUANA','MELCHOR','1232',_binary '\0','56474312','juan.melchorcito@gmail.com','2022-01-14 00:00:00'),(4,'MIGUEL','LOPEZ','5647211',_binary '','24827371','miguel.lopez@gmail.com','2022-01-27 00:00:00'),(5,'JENNIFER','ALONZO','57720101',_binary '\0','56743719','jeny.al@gmail.com','2022-03-11 00:00:00'),(6,'JORGE','CIPRIANO','38292',_binary '','26572819','jorgito.cp@gmail.com','2022-04-18 00:00:00'),(7,'MARTIN','MIGUELANGEL','54321',_binary '','56473821','martinsito@gmail.com','2022-01-01 00:00:00');
/*!40000 ALTER TABLE `clientes` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `compras`
--

DROP TABLE IF EXISTS `compras`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `compras` (
  `idCompra` int NOT NULL AUTO_INCREMENT,
  `no_orden_compra` int DEFAULT NULL,
  `idProveedor` int NOT NULL,
  `fecha_orden` date DEFAULT NULL,
  `fechaingreso` datetime DEFAULT NULL,
  PRIMARY KEY (`idCompra`),
  KEY `fk_Compras_Proveedores1_idx` (`idProveedor`),
  CONSTRAINT `fk_Compras_Proveedores1` FOREIGN KEY (`idProveedor`) REFERENCES `proveedores` (`idProveedor`)
) ENGINE=InnoDB AUTO_INCREMENT=35 DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `compras`
--

LOCK TABLES `compras` WRITE;
/*!40000 ALTER TABLE `compras` DISABLE KEYS */;
INSERT INTO `compras` VALUES (1,123456,2,'2022-01-01','2022-01-01 00:00:00'),(3,1341,2,'2000-01-01','2000-01-01 00:00:00'),(4,38282,2,'2000-01-01','2000-01-01 00:00:00'),(5,747387,2,'2001-01-01','2001-01-01 00:00:00'),(6,13443,2,'2001-01-01','2001-01-01 00:00:00'),(7,28383,2,'2022-03-03','2022-03-03 00:00:00'),(8,348383,2,'2022-01-01','2022-01-01 00:00:00'),(9,37373,2,'2022-01-01','2022-01-01 00:00:00'),(10,7474,2,'2022-01-01','2022-01-01 00:00:00'),(11,56373,2,'2022-01-01','2022-01-01 00:00:00'),(12,3443,2,'2022-01-01','2022-01-01 00:00:00'),(13,21321,2,'2022-01-01','2022-01-01 00:00:00'),(14,2332,1,'2022-01-01','2022-01-01 00:00:00'),(15,23213,1,'2022-01-01','2022-01-01 00:00:00'),(16,23292,2,'2000-01-01','2000-01-01 00:00:00'),(17,23832,2,'2000-01-01','2000-01-01 00:00:00'),(20,33838,2,'2000-01-01','2000-01-01 00:00:00'),(21,2383,2,'2000-01-01','2000-01-01 00:00:00'),(22,123321,1,'2000-01-01','2000-01-01 00:00:00'),(23,423123,2,'2000-01-01','2000-01-01 00:00:00'),(24,239392,2,'2000-01-01','2002-01-01 00:00:00'),(25,2312,1,'2000-01-01','2000-01-01 00:00:00'),(26,1313,1,'2000-01-01','2000-01-01 00:00:00'),(27,3432,1,'2000-01-01','2000-01-01 00:00:00'),(28,1231,1,'2000-01-01','2000-01-01 00:00:00'),(29,12412,1,'2000-01-01','2000-01-01 00:00:00'),(30,12441,1,'2000-01-01','2000-01-01 00:00:00'),(31,1,1,'2000-01-01','2000-01-01 00:00:00'),(32,1,1,'2022-01-01','2022-01-01 00:00:00'),(33,123,1,'2000-01-01','2000-01-01 00:00:00'),(34,467272,1,'2022-01-01','2022-01-01 00:00:00');
/*!40000 ALTER TABLE `compras` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `compras_detalle`
--

DROP TABLE IF EXISTS `compras_detalle`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `compras_detalle` (
  `idCompra_detalle` bigint NOT NULL AUTO_INCREMENT,
  `idCompra` int NOT NULL,
  `idProducto` int NOT NULL,
  `cantidad` int DEFAULT NULL,
  `precio_costo_unitario` decimal(8,2) DEFAULT NULL,
  PRIMARY KEY (`idCompra_detalle`),
  KEY `fk_Compras_detalle_Compras1_idx` (`idCompra`),
  KEY `fk_Compras_detalle_Productos1_idx` (`idProducto`),
  CONSTRAINT `fk_Compras_detalle_Compras1` FOREIGN KEY (`idCompra`) REFERENCES `compras` (`idCompra`),
  CONSTRAINT `fk_Compras_detalle_Productos1` FOREIGN KEY (`idProducto`) REFERENCES `productos` (`idProducto`)
) ENGINE=InnoDB AUTO_INCREMENT=15 DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `compras_detalle`
--

LOCK TABLES `compras_detalle` WRITE;
/*!40000 ALTER TABLE `compras_detalle` DISABLE KEYS */;
INSERT INTO `compras_detalle` VALUES (1,1,2,20,20.40),(3,9,2,20,57.20),(6,13,5,100,25.00),(7,20,5,100,40.00),(8,21,5,100,50.00),(9,22,2,24,20.00),(10,23,2,24,0.50),(11,24,5,128,75.20),(12,31,2,50,15.20),(13,33,2,43,1240.99),(14,34,2,5,1240.99);
/*!40000 ALTER TABLE `compras_detalle` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `empleados`
--

DROP TABLE IF EXISTS `empleados`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `empleados` (
  `idEmpleado` int NOT NULL AUTO_INCREMENT,
  `nombres` varchar(60) DEFAULT NULL,
  `apellidos` varchar(60) DEFAULT NULL,
  `direccion` varchar(80) DEFAULT NULL,
  `telefono` varchar(25) DEFAULT NULL,
  `DPI` varchar(15) DEFAULT NULL,
  `genero` bit(1) DEFAULT NULL,
  `fecha_nacimiento` date DEFAULT NULL,
  `idPuesto` smallint NOT NULL,
  `fecha_inicio_labores` date DEFAULT NULL,
  `fechaingreso` datetime DEFAULT NULL,
  PRIMARY KEY (`idEmpleado`),
  KEY `fk_Empleados_Puestos1_idx` (`idPuesto`),
  CONSTRAINT `fk_Empleados_Puestos1` FOREIGN KEY (`idPuesto`) REFERENCES `puestos` (`idPuesto`)
) ENGINE=InnoDB AUTO_INCREMENT=7 DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `empleados`
--

LOCK TABLES `empleados` WRITE;
/*!40000 ALTER TABLE `empleados` DISABLE KEYS */;
INSERT INTO `empleados` VALUES (2,'JUANITO','ACEVEDO','CIUDAD','57448383','12828283',_binary '','2000-02-19',1,'2021-08-21','2021-09-21 00:00:00'),(4,'GICELLA','RUIZ','CIUDAD','43910290','492921910101',_binary '\0','1990-01-01',4,'2020-02-01','2020-02-10 00:00:00'),(5,'CARLOS','GARCIA','CIUDAD','21204910','573281010101',_binary '','1998-05-14',6,'2015-06-10','2015-07-01 00:00:00'),(6,'MONICA','LORENZO','CIUDAD','54939382','291283820101',_binary '\0','1999-04-11',6,'2014-11-02','2014-11-10 00:00:00');
/*!40000 ALTER TABLE `empleados` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `marcas`
--

DROP TABLE IF EXISTS `marcas`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `marcas` (
  `idMarca` smallint NOT NULL AUTO_INCREMENT,
  `marca` varchar(50) DEFAULT NULL,
  PRIMARY KEY (`idMarca`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `marcas`
--

LOCK TABLES `marcas` WRITE;
/*!40000 ALTER TABLE `marcas` DISABLE KEYS */;
INSERT INTO `marcas` VALUES (2,'TOLEDO'),(3,'TOSHIBA'),(4,'HUAWEI');
/*!40000 ALTER TABLE `marcas` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `productos`
--

DROP TABLE IF EXISTS `productos`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `productos` (
  `idProducto` int NOT NULL AUTO_INCREMENT,
  `producto` varchar(50) DEFAULT NULL,
  `idMarca` smallint NOT NULL,
  `Descripcion` varchar(100) DEFAULT NULL,
  `Imagen` varchar(30) DEFAULT NULL,
  `precio_costo` decimal(8,2) DEFAULT NULL,
  `precio_venta` decimal(8,2) DEFAULT NULL,
  `existencia` int DEFAULT NULL,
  `fecha_ingreso` datetime DEFAULT NULL,
  PRIMARY KEY (`idProducto`),
  KEY `fk_Productos_Marcas1_idx` (`idMarca`),
  CONSTRAINT `fk_Productos_Marcas1` FOREIGN KEY (`idMarca`) REFERENCES `marcas` (`idMarca`)
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `productos`
--

LOCK TABLES `productos` WRITE;
/*!40000 ALTER TABLE `productos` DISABLE KEYS */;
INSERT INTO `productos` VALUES (2,'FRIJOL',2,'ROJO','htt//',20.40,25.11,78,'2022-05-01 00:00:00'),(5,'AZUCAR',2,'MORENA','http//',23.00,25.00,100,'2022-04-01 00:00:00');
/*!40000 ALTER TABLE `productos` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `proveedores`
--

DROP TABLE IF EXISTS `proveedores`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `proveedores` (
  `idProveedor` int NOT NULL AUTO_INCREMENT,
  `proveedor` varchar(60) DEFAULT NULL,
  `nit` varchar(12) DEFAULT NULL,
  `direccion` varchar(80) DEFAULT NULL,
  `telefono` varchar(25) DEFAULT NULL,
  PRIMARY KEY (`idProveedor`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `proveedores`
--

LOCK TABLES `proveedores` WRITE;
/*!40000 ALTER TABLE `proveedores` DISABLE KEYS */;
INSERT INTO `proveedores` VALUES (1,'CLARO','39230932-1','GUATEMALA','20220101'),(2,'TIGO','209493-1','GUATEMALA','21010101');
/*!40000 ALTER TABLE `proveedores` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `puestos`
--

DROP TABLE IF EXISTS `puestos`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `puestos` (
  `idPuesto` smallint NOT NULL AUTO_INCREMENT,
  `puesto` varchar(50) DEFAULT NULL,
  PRIMARY KEY (`idPuesto`)
) ENGINE=InnoDB AUTO_INCREMENT=7 DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `puestos`
--

LOCK TABLES `puestos` WRITE;
/*!40000 ALTER TABLE `puestos` DISABLE KEYS */;
INSERT INTO `puestos` VALUES (1,'CAJERO'),(2,'LIMPIEZA'),(3,'ADMINISTRACION'),(4,'RECEPTOR'),(6,'CONTADOR');
/*!40000 ALTER TABLE `puestos` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ventas`
--

DROP TABLE IF EXISTS `ventas`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `ventas` (
  `idVenta` int NOT NULL AUTO_INCREMENT,
  `nofactura` int DEFAULT NULL,
  `serie` varchar(50) DEFAULT NULL,
  `fechafactura` date DEFAULT NULL,
  `idCliente` int NOT NULL,
  `idEmpleado` int NOT NULL,
  `fechaingreso` datetime DEFAULT NULL,
  PRIMARY KEY (`idVenta`),
  KEY `fk_Ventas_Clientes_idx` (`idCliente`),
  KEY `fk_Ventas_Empleados1_idx` (`idEmpleado`),
  CONSTRAINT `fk_Ventas_Clientes` FOREIGN KEY (`idCliente`) REFERENCES `clientes` (`idCliente`),
  CONSTRAINT `fk_Ventas_Empleados1` FOREIGN KEY (`idEmpleado`) REFERENCES `empleados` (`idEmpleado`)
) ENGINE=InnoDB AUTO_INCREMENT=16 DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ventas`
--

LOCK TABLES `ventas` WRITE;
/*!40000 ALTER TABLE `ventas` DISABLE KEYS */;
INSERT INTO `ventas` VALUES (1,1233,'A','2022-01-01',2,2,'2022-01-01 00:00:00'),(3,41231,'B','2022-01-01',2,2,'2022-01-01 00:00:00'),(4,4231,'A','2022-01-01',2,2,'2022-01-01 00:00:00'),(5,46737,'A','2022-01-01',2,2,'2022-01-01 00:00:00'),(6,23412,'B','2022-01-01',2,2,'2022-01-01 00:00:00'),(7,23213,'C','2022-01-01',2,2,'2022-01-01 00:00:00'),(8,32831,'C','2022-01-01',2,2,'2022-01-01 00:00:00'),(9,23038,'A','2022-01-01',2,2,'2022-01-01 00:00:00'),(10,5621,'B','2022-01-01',2,2,'2022-01-01 00:00:00'),(11,9877482,'a','2022-01-01',2,2,'2022-01-01 00:00:00'),(12,82383,'A','2022-01-01',2,2,'2022-01-01 00:00:00'),(13,9088,'A','2022-01-01',2,2,'2022-01-01 00:00:00'),(14,57473,'A','2022-04-04',7,2,'2022-04-04 00:00:00'),(15,577472,'A','2022-01-01',1,2,'2022-01-01 00:00:00');
/*!40000 ALTER TABLE `ventas` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `ventas_detalle`
--

DROP TABLE IF EXISTS `ventas_detalle`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `ventas_detalle` (
  `idVenta_detalle` bigint NOT NULL AUTO_INCREMENT,
  `idVenta` int NOT NULL,
  `idProducto` int NOT NULL,
  `cantidad` int DEFAULT NULL,
  `precio_unitario` decimal(8,2) DEFAULT NULL,
  PRIMARY KEY (`idVenta_detalle`),
  KEY `fk_Ventas_detalle_Ventas1_idx` (`idVenta`),
  KEY `fk_Ventas_detalle_Productos1_idx` (`idProducto`),
  CONSTRAINT `fk_Ventas_detalle_Productos1` FOREIGN KEY (`idProducto`) REFERENCES `productos` (`idProducto`),
  CONSTRAINT `fk_Ventas_detalle_Ventas1` FOREIGN KEY (`idVenta`) REFERENCES `ventas` (`idVenta`)
) ENGINE=InnoDB AUTO_INCREMENT=11 DEFAULT CHARSET=utf8mb3;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ventas_detalle`
--

LOCK TABLES `ventas_detalle` WRITE;
/*!40000 ALTER TABLE `ventas_detalle` DISABLE KEYS */;
INSERT INTO `ventas_detalle` VALUES (1,1,2,22,10.00),(2,7,2,10,25.00),(3,8,2,30,22.00),(4,9,2,22,10.00),(5,10,2,10,22.00),(6,11,2,20,10.00),(7,12,2,10,30.00),(8,13,2,5,10.00),(9,14,2,10,50.00);
/*!40000 ALTER TABLE `ventas_detalle` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2022-06-05 23:16:10
