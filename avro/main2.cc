#include <fstream>

#include "C.h"
#include "avro/Encoder.hh"
#include "avro/Decoder.hh"
#include "avro/Compiler.hh"
#include "avro/GenericDatum.hh"
#include "avro/Generic.hh"

void printRecord(avro::GenericDatum& datum) {
	const avro::GenericRecord& r = datum.value<avro::GenericRecord>();
		std::cout << "Field-count: " << r.fieldCount() << std::endl;
		for (size_t i = 0; i < r.fieldCount(); ++i) {
			const avro::GenericDatum& field = r.fieldAt(i);
			switch (field.type()) {
				case avro::AVRO_FLOAT:
					std::cout << "Double Field: " << r.schema()->nameAt(i) << " Value: " << field.value<float>() << std::endl;
					break;
				case avro::AVRO_STRING:
					std::cout << "String Field: " << r.schema()->nameAt(i) << " Value: " << field.value<std::string>() << std::endl;
					break;	
				default:
					std::cout << "Unknown field type" << std::endl;
			}
		}
}

int main() {

	std::ifstream ifsW("/home/erostamas/repos/common/avro/writer.json");
	std::ifstream ifsR("/home/erostamas/repos/common/avro/reader.json");
	 
	avro::ValidSchema writerSchema;
	avro::ValidSchema readerSchema;
	avro::compileJsonSchema(ifsW, writerSchema);
	avro::compileJsonSchema(ifsR, readerSchema);
	
	std::shared_ptr<avro::OutputStream> out = avro::memoryOutputStream();
	avro::EncoderPtr e = avro::binaryEncoder();
	e->init(*out);
	
	avro::GenericDatum datum(writerSchema);
	
	
	avro::GenericRecord& r = datum.value<avro::GenericRecord>();
	
	r.field("a").value<float>() = 12.34;
	r.field("b").value<std::string>() = "hellobello";
	
	avro::GenericWriter gwriter(writerSchema, e);
	gwriter.write(datum);
	out->flush();
	e->flush();
	
	std::cout << "Bytes written: " << out->byteCount() << std::endl;
	
	//std::vector<uint8_t> bytes;
	//size_t len = out->byteCount();

        //std::shared_ptr<avro::InputStream> in = avro::memoryInputStream(*out);
        //avro::StreamReader* reader = new avro::StreamReader(*in);
        //
        //bytes.reserve(len);
        //
        //while (reader->hasMore()) {
		//	
        //    uint8_t c = reader->read();
		//	std::cout << "READ BYTE: " << int(c) << std::endl;
        //    bytes.push_back(c);
        //}

	std::shared_ptr<avro::InputStream> in = avro::memoryInputStream(*out);
	//avro::DecoderPtr d = avro::binaryDecoder();
	avro::DecoderPtr d = avro::resolvingDecoder(writerSchema, readerSchema,avro::binaryDecoder());
	d->init(*in);
	
	avro::GenericDatum readDatum(readerSchema);
	avro::decode(*d, readDatum);
	printRecord(readDatum);
	//std::cout << "Type: " << datum.type() << std::endl;
	//if (datum.type() == avro::AVRO_RECORD) {
	//	const avro::GenericRecord& r = datum.value<avro::GenericRecord>();
	//	std::cout << "Field-count: " << r.fieldCount() << std::endl;
	//	if (r.fieldCount() == 2) {
	//		const avro::GenericDatum& f0 = r.fieldAt(0);
	//		if (f0.type() == avro::AVRO_DOUBLE) {
	//			std::cout << "Real: " << f0.value<double>() << std::endl;
	//		}
	//		const avro::GenericDatum& f1 = r.fieldAt(1);
	//		if (f1.type() == avro::AVRO_DOUBLE) {
	//			std::cout << "Imaginary: " << f1.value<double>() << std::endl;
	//		}
	//	}
	//}
	return 0;
}