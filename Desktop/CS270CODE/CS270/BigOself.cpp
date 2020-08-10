float data[15] = {1.0, 1.5, 1.3, 1.8, 2.15, 2.09, 2.51, 2.69, 3.80, 3.14159, 3.3, 2.91, 2.98, 1.5, 1.6};

float result[13];

float average(int i, int count){
	float result = 0.0;
	for (int offset = 0, offset < count; offset++){
		result += data[i];
	}
	return result / float(count);
}

void smooth() {
	//Result[i] = average(data[i], data[i+1], data[i+2])
	for (int i= = 0; i <16-count; i++) {
		result[i] = average(i, count);
	}
}