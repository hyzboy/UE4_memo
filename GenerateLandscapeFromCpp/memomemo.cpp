TArray<uint16> heightmap_expand(TArray<uint16> Data, int width, int height, int new_width, int new_height) {
	uint16 *original_data_buf = Data.GetData();
	int data_len = Data.Num();

	TArray<uint16> original_data;
	original_data.Init(0, data_len / 2);

	FMemory::Memcpy(original_data.GetData(), original_data_buf, data_len);

	int offset_x = (new_width - width) / 2;
	int offset_y = (new_height - height) / 2;

	TArray<uint16> new_data = LandscapeEditorUtils::ExpandData(original_data, 0, 0, width - 1, height - 1, -offset_x, -offset_y, new_width - offset_x - 1, new_height - offset_y - 1);

	return new_data;
}
