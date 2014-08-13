      <div class="panel-footer">
        <div class="row">
          <div class="col-lg-2 col-sm-6">
            <div class="circle-tile fade">
              <div class="circle-tile-heading lightblue">
                <i class="fa fa-th-large fa-fw fa-2x"></i>
              </div>
              <div class="circle-tile-content lightblue">
                <div class="circle-tile-description text-faded">
                  <p class="h5" id="b-nblock">{$NETWORK.block}</p>
                </div>
                <div class="circle-tile-number text-faded">
                  <p class="h6">当前区块</p>
                </div>
              </div>
            </div>
          </div>
          <div class="col-lg-2 col-sm-6">
            <div class="circle-tile fade">
              <div class="circle-tile-heading lightblue">
                <i class="fa fa-bar-chart-o fa-flip-horizontal fa-fw fa-2x"></i>
              </div>
              <div class="circle-tile-content lightblue">
                <div class="circle-tile-description text-faded">
                  <p class="h5" id="b-roundprogress">{$ESTIMATES.percent|number_format:"2"}%</p>
                </div>
                <div class="circle-tile-number text-faded">
                  <p class="h6">预期贡献</p>
                </div>
              </div>
            </div>
          </div>
          <div class="col-lg-2 col-sm-6">
            <div class="circle-tile fade">
              <div class="circle-tile-heading lightblue">
                <i class="fa fa-money fa-fw fa-2x"></i>
              </div>
              <div class="circle-tile-content lightblue">
                <div class="circle-tile-description text-faded">
                  <p class="h5" id="b-payout">{$GLOBAL.userdata.estimates.payout|number_format:"8"}</p>
                </div>
                <div class="circle-tile-number text-faded">
                  <p class="h6">{$GLOBAL.config.currency} 估计收益</p>
                </div>
              </div>
            </div>
          </div>
          <div class="col-lg-2 col-sm-6">
            <div class="circle-tile fade">
              <div class="circle-tile-heading lightblue">
                <i class="fa fa-map-marker fa-fw fa-2x"></i>
              </div>
              <div class="circle-tile-content lightblue">
                <div class="circle-tile-description text-faded">
                  <p class="h5" id="b-diff">{$NETWORK.difficulty|number_format:"8"}</p>
                </div>
                <div class="circle-tile-number text-faded">
                  <p class="h6">当前难度</p>
                </div>
              </div>
            </div>
          </div>
          <div class="col-lg-2 col-sm-6">
            <div class="circle-tile fade">
              <div class="circle-tile-heading lightblue">
                <i class="fa fa-sitemap fa-fw fa-2x"></i>
              </div>
              <div class="circle-tile-content lightblue">
                <div class="circle-tile-description text-faded">
                  <p class="h5 up" id="b-nextdiff">{if $GLOBAL.nethashrate > 0}{$NETWORK.EstNextDifficulty|number_format:"8"}{else}n/a{/if}</p>
                  <p class="h6" id="b-nextdiffc">{if $GLOBAL.nethashrate > 0}将在下 {$NETWORK.BlocksUntilDiffChange} 个区块后{else}No Estimates{/if}</p>
                </div>
                <div class="circle-tile-number text-faded">
                  <p class="h6">下一次难度</p>
                </div>
              </div>
            </div>
          </div>
          <div class="col-lg-2 col-sm-6">
            <div class="circle-tile fade">
              <div class="circle-tile-heading lightblue">
                <i class="fa fa-clock-o fa-fw fa-2x"></i>
              </div>
              <div class="circle-tile-content lightblue">
                <div class="circle-tile-description text-faded">
                  <p class="h5" id="b-esttimeperblock">{$NETWORK.EstTimePerBlock|seconds_to_words}</p>
                </div>
                <div class="circle-tile-number text-faded">
                  <p class="h6">每块估计平均时间</p>
                </div>
              </div>
            </div>
          </div>
        </div>
      </div>
