import time
import depthai as dai

def main():
    print("DepthAI version: {}".format(dai.__version__))

    devs = []
    while len(devs) <= 0:
        devs = dai.Device.getAllConnectedDevices()
        for dev in devs:
            print(f'Found device: {dev}')
        time.sleep(1)

    print("Connecting to first device...")
    with dai.Device() as d:
        print(f'{d.getConnectedCameraFeatures()}')
