ffmpeg -i sound-mp3.bin -r:a 44100 -ac 1 -c:a pcm_f32le -f f32le input.f32le

ffmpeg -r:a 44100 -ac 1 -f f32le -i result.f32le result.mp3;

ffmpeg -r:a 44100 -ac 1 -f f32le -i echoed.f32le echoed.mp3;
