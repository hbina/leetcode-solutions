package tools;

public class Performance {

	private long start;
	private long end;

	public Performance() {
		start = 0;
		end = 0;
	}

	public void start() {
		start = System.currentTimeMillis();
	}

	public void end() {
		end = System.currentTimeMillis();
	}

	public long getTime() {
		return end - start;
	}

	public float getTimeInSeconds() {
		return (float) (getTime() / 1000);
	}
}
