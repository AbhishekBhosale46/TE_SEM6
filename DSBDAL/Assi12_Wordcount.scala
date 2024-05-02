val data = sc.textFile("input.txt");
data.collect;

val splitdata = data.flatMap(line => line.split(" "));
splitdata.collect;

val mapdata = splitdata.map(word => (word,1));
mapdata.collect;

val reducedata = mapdata.reduceByKey(_+_);
reducedata.collect;